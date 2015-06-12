
/**
 * Gallery Tabs Object
 */
var stanford_gallery_tabs = {
  tabs : []
};

/**
 * initiates slick carousels
 */

(function ($) {

  // Prevent space bar from jumping down page on views rows.
  $(document).keydown(function (e) {
    var key = e.charCode ? e.charCode : e.keyCode ? e.keyCode : 0;
    if (key == 32) {
      if ($(e.target).hasClass("views-row")) {
        e.preventDefault();
      }
    }
  });

  // Behaviors!
  Drupal.behaviors.stanford_gallery_tabs = {
    attach: function (context, settings) {



      // IMAGE
      // -----------------------------------------------------------------------
      $(".stanford-gallery-tabs-image .view-content").slick({
        fade : true,
        arrows : false,
        dots : false,
        adaptiveHeight : true
      });

      // Tabs
      // -----------------------------------------------------------------------

      // Allow tabs to be focusable.
      $(".stanford-gallery-tabs-list .view-content")
        .attr("role", "group")
        .attr("aria-labelledby", "gallery-tabs-heading");
      $(".stanford-gallery-tabs-list .view-content .views-row")
        .attr("aria-expanded", false)
        .attr("role", "tab")
        .attr("tabindex", 0);

      // Trigger the click when user hits space bar.
      $(".stanford-gallery-tabs-list .view-content .views-row").keyup(function(e){
         if(e.keyCode == 32){
            $(this).click();
            e.preventDefault();
            return;
         }
      });

      // The real click handler.
      $(".stanford-gallery-tabs-list .view-content .views-row").click(function(e) {
        stanford_gallery_tabs.click_tab(this);
      });

      // Set the active tab to start.
      $(".stanford-gallery-tabs-list .view-content .views-row:first").click();


    }
  };

/**
 * [click_tab description]
 * @param  {[type]} args [description]
 * @return {[type]}      [description]
 */
  stanford_gallery_tabs.click_tab = function(element, args) {
    var tabs = this.get_tabs(element);
    tabs.removeClass("active-tab");
    tabs.attr("aria-expanded", false);

    $(element).addClass("active-tab");
    var index = this.get_index(element);
    $(".stanford-gallery-tabs-image .view-content").slick("slickGoTo", index);
    $(element).attr("aria-expanded", true);
  };

  /**
   * [get_tabs description]
   * @return {[type]} [description]
   */
  stanford_gallery_tabs.get_tabs = function(element) {

    if (this.tabs.length) {
      return this.tabs;
    }

    this.tabs = $(element).parents(".view-content").find(".views-row");

    return this.tabs;
  };

  /**
   * [get_index description]
   * @param  {[type]} element [description]
   * @return {[type]}         [description]
   */
  stanford_gallery_tabs.get_index = function(element) {
    var tabs = this.get_tabs(element);
    var index = tabs.index(element);
    return index;
  };

})(jQuery);
