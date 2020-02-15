demo.state2 = function(){};
demo.state2.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#adef3f';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};