// $Id$
;(function($, undefined){

  /**
   * When set to enable mediaelement for all audi/video files add it to the page.
   */
  Drupal.behaviors.mediaelement = function(context) {
    if (Drupal.settings.mediaelement.all != undefined && Drupal.settings.mediaelement.all) {
      $('audio,video').mediaelementplayer();
    }
  }

})(jQuery);