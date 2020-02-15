demo.state4 = function(){};
demo.state4.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#e60000';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};