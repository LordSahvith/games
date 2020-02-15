demo.state9 = function(){};
demo.state9.prototype = {
    preload: function(){},
    create: function(){
        game.stage.backgroundColor = '#ff0000';
        
        addChangeStateEventListeners();
    },
    update: function(){}
};