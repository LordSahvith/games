demo.state7 = function(){};
demo.state7.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#99cc00';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};