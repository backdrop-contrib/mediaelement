<?php
// $Id$

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
      '#value' => '<p>'. t('The MediaElement.js library is not installed. Please download the library from <a href="!url">MediaElementjs.com</a> and place it in your libraries folder.', array('!url' => 'http://mediaelementjs.com')) .'</p>',
    );
  }

  $form['mediaelement_sitewide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable MediaElement.js site wide'),
    '#default_value' => variable_get('mediaelement_sitewide', FALSE),
  );

  $path = libraries_get_path('mediaelement');
  $form['test'] = array(
    '#value' => '<video width="360" height="203" id="player1" src="/'. $path .'/media/jsaddington.mp4"><p>Your browser leaves much to be desired.</p></video>',
  );

  return system_settings_form($form);
}