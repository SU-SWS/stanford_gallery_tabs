(function ($) {

  // Behaviors!
  Drupal.behaviors.stanford_gallery_tabs_admin = {
    attach: function (context, settings) {
      $(".field-name-field-su-gt-quotation textarea", context).keypress(function(e) {
        var valu = $(this).val();
        var count = valu.length;
        var max = 150;

        if (count >= max) {
          $(this).val(valu.slice(0, max));
          alert(Drupal.t("The quotation can only be " + max + " characters"));
          e.preventDefault();
        }
      });
    }
  };

})(jQuery);
