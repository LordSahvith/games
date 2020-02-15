demo.state5 = function(){};
demo.state5.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#cc33ff';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};