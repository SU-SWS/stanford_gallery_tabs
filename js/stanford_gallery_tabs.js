
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

  // Prevent space bar from jumping down page.
  $(document).keydown(function (e) {
    var key = e.charCode ? e.charCode : e.keyCode ? e.keyCode : 0;
    if (key == 32)
       e.preventDefault();
 });

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
      $(".stanford-gallery-tabs-list .view-content .views-row").attr("tabindex", 1);

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

})(jQuery);

/**
 * [click_tab description]
 * @param  {[type]} args [description]
 * @return {[type]}      [description]
 */
stanford_gallery_tabs.click_tab = function(element, args) {
  var tabs = this.get_tabs(element);
  tabs.removeClass("active-tab");
  jQuery(element).addClass("active-tab");
  var index = this.get_index(element);
  jQuery(".stanford-gallery-tabs-image .view-content").slick("slickGoTo", index);
};

/**
 * [get_tabs description]
 * @return {[type]} [description]
 */
stanford_gallery_tabs.get_tabs = function(element) {

  if (this.tabs.length) {
    return this.tabs;
  }

  this.tabs = jQuery(element).parents(".view-content").find(".views-row");

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
