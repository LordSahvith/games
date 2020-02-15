demo.state8 = function(){};
demo.state8.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#cc6600';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};