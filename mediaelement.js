(function($, Backdrop, undefined){
  /**
   * When set to enable mediaelement for all audio/video files add it to the page.
   */
  Backdrop.behaviors.mediaelement = {
    attach: function(context, settings) {
      if (settings.mediaelement !== undefined) {
        // @todo Remove anonymous function.
        $.each(settings.mediaelement, function(selector, options) {
          var opts;
          $(selector, context).once('mediaelement', function() {
            if (options.controls) {
              $(this).mediaelementplayer(options.opts);
            }
            else {
              $(this).mediaelement();
            }
          });
        });
      }
      // The global option is separate from the other selectors as it should be
      // run after any other selectors.
      if (settings.mediaelementAll !== undefined) {
        $('a.media,video', context).once('mediaelement', function() {
          $(this).mediaelementplayer();
        });
      }
    }
  };
})(jQuery, Backdrop);