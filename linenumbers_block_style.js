(function ($) {
  Drupal.behaviors.linenumbers = {
    attach: function(context, settings) {
      var margins = [];
      var elementArray = $('.ln_fl').children().map(function(){
        var text_margins = ($(this).css('margin'));
        margins.push(text_margins);
      });
      var numberArray = $('aside').children();
      $.each(numberArray, function(index, value){
        console.log(margins[index]);
        $(this).css({
          'margin' : margins[index],
          'display' : 'block',
          'margin-left' : '0',
          'margin-right' : '0',
        });
      });
    }
  }
}) (jQuery);
