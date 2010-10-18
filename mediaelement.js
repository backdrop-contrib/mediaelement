// $Id$
;(function($, undefined){
  /**
   * When set to enable mediaelement for all audio/video files add it to the page.
   */
  Drupal.behaviors.mediaelement = {
    attach: function(context, settings) {
      if (Drupal.settings.mediaelement != undefined) {
        $.each(Drupal.settings.mediaelement, function(selector, options) {
          $(selector, context).once('mediaelement', function() {
            if (options.controls) {
              $(this).mediaelementplayer(options);
            }
            else {
              $(this).mediaelement();
            }
          });
        })
      }
      // The global option is seperate from the other selectors as it should be
      // run after any other selectors.
      if (Drupal.settings.mediaelementAll != undefined) {
        $('video,audio', context).once('mediaelement', function() {
          $(this).mediaelementplayer();
        });
      }
    }
  }
})(jQuery);