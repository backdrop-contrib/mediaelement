<?php

/**
 * @file
 * Admin only functionality for the mediaelement module.
 */

/**
 * Menu form callback; Display the MediaElement admin form.
 */
function mediaelement_admin_form() {
  $form = array();

  // Detect if the library is available. If it is not available display a
  // message.
  $libraries = libraries_get_libraries();
  if (!isset($libraries['mediaelement'])) {
    $form['message'] = array(
      '#markup' => '<p>' . t('The MediaElement.js library is not installed. Please download the library from <a href="!url">MediaElementjs.com</a> and place it in your libraries folder.', array('!url' => 'http://mediaelementjs.com')) . '</p>',
    );
  }

  $form['mediaelement_sitewide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable MediaElement.js site wide'),
    '#default_value' => config_get('mediaelement.settings','mediaelement_sitewide'),
  );

  // Display a sample video. We add the library here because we cannot be sure
  // it is otherwise included in the page.
  backdrop_add_library('mediaelement', 'mediaelement');
  backdrop_add_js(backdrop_get_path('module', 'mediaelement') . '/mediaelement.js');
  backdrop_add_js(array('mediaelementAll' => TRUE), array('type' => 'setting'));
  $path = libraries_get_path('mediaelement', TRUE);
  $form['test'] = array(
    '#markup' => '<video width="360" height="203" id="player1" src="' . $path . '/media/echo-hereweare.mp4"><p>Your browser leaves much to be desired.</p></video>',
  );

	$config = config('mediaelement.settings');

	$form['mediaelement_video_default_width'] = array(
	  '#type' => 'textfield',
		'#title' => t('Video width'),
		'#description' => t('Set the width of the video display'),
		'#default_value' => $config->get('mediaelement_video_default_width'),
    '#required' => TRUE,
    '#size' => 5,
	);

		$form['mediaelement_video_default_height'] = array(
	  '#type' => 'textfield',
		'#title' => t('Video height'),
		'#description' => t('Set the height of the media display'),
		'#default_value' => $config->get('mediaelement_video_default_height'),
    '#required' => TRUE,
    '#size' => 5,
	);

		$form['mediaelement_audio_default_height'] = array(
	  '#type' => 'textfield',
		'#title' => t('Audio height'),
		'#description' => t('Set the height of the audio display'),
		'#default_value' => $config->get('mediaelement_audio_default_height'),
    '#required' => TRUE,
    '#size' => 5,
	);

		$form['mediaelement_audio_default_width'] = array(
	  '#type' => 'textfield',
		'#title' => t('Audio width'),
		'#description' => t('Set the width of the audio display'),
		'#default_value' => $config->get('mediaelement_audio_default_width'),
    '#required' => TRUE,
    '#size' => 5,
	);

  // Add a submit button
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  // Return the form
  return $form;
}


/**
 * Process mediaelement_admin_settings form.
 */
function mediaelement_admin_form_submit($form, &$form_state) {

  $config = config('mediaelement.settings');
	$config->set('mediaelement_sitewide', $form_state['values']['mediaelement_sitewide']);
	$config->set('mediaelement_video_default_width', $form_state['values']['mediaelement_video_default_width']);
	$config->set('mediaelement_video_default_height', $form_state['values']['mediaelement_video_default_height']);
	$config->set('mediaelement_audio_default_width', $form_state['values']['mediaelement_audio_default_width']);
	$config->set('mediaelement_audio_default_height', $form_state['values']['mediaelement_audio_default_height']);

	$config->save();

  backdrop_set_message(t('The configuration options have been saved.'));
}