// $Id$
;(function($){
  /**
   * When set to enable mediaelement for all audi/video files add it to the page.
   */
  Drupal.behaviors.mediaelement = {
    attach: function(context, settings) {
      $('video, audio').mediaelementplayer();
    }
  }

})(jQuery);