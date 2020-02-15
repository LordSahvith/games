var demo = {};
var centerX = 1500 / 2;
var centerY = 1000 / 2;
var me;
var speed = 8;

demo.state0 = function(){};

demo.state0.prototype = {
    
    preload: function(){
        
        game.load.spritesheet('me', 'img/me-sprite.png', 500, 500);
        game.load.image('bg1', 'img/bg.png');
        
    },
    
    create: function(){
        
        game.physics.startSystem(Phaser.Physics.ARCADE);
        game.stage.backgroundColor = '#ffff00';
               
        addChangeStateEventListeners();
        game.scale.scaleMode = Phaser.ScaleManager.SHOW_ALL;
        
        game.world.setBounds(0, 0, 2813, 1000);
        
        var bg = game.add.sprite(0, 0, 'bg1');
        
        me = game.add.sprite(centerX, centerY, 'me');
        me.anchor.setTo(0.5, 0.5);
        me.scale.setTo(1.0, 1.0);
        game.physics.enable(me);
        me.body.collideWorldBounds = true;        
        me.animations.add('walk', [0, 1, 2, 3, 4]);
        
        game.camera.follow(me);        
        game.camera.deadzone = new Phaser.Rectangle(centerX - 300, 0, 600, 1000);
        
    },
    
    update: function(){
        
        if(game.input.keyboard.isDown(Phaser.Keyboard.D)) {
            
            me.scale.setTo(1.0, 1.0);
            me.x += speed;
            me.animations.play('walk', 10, true);
            
        } else if (game.input.keyboard.isDown(Phaser.Keyboard.A)) {
            
            me.scale.setTo(-1.0, 1.0);
            me.x -= speed;
            
            me.animations.play('walk', 10, true);
            
        } else if(game.input.keyboard.isDown(Phaser.Keyboard.W)) {
            
            me.y -= speed;
            
            if (me.y < 320) {
                me.y = 320;
            }
            
            me.animations.play('walk', 10, true);
            
        } else if (game.input.keyboard.isDown(Phaser.Keyboard.S)) {
            
            me.y += speed;
            me.animations.play('walk', 10, true);
            
        } else {
            
            me.animations.stop('walk');
            me.frame = 0;
            
        }
        
    }
};

function changeState(i, stateNum) {
    
    console.log('state ' + stateNum);
    game.state.start('state' + stateNum);
    
}

function addKeyCallback(key, fn, args) {
    
    game.input.keyboard.addKey(key).onDown.add(fn, null, null, args);
    
}

function addChangeStateEventListeners() {
    
    addKeyCallback(Phaser.Keyboard.ZERO, changeState, 0);
    addKeyCallback(Phaser.Keyboard.ONE, changeState, 1);
    addKeyCallback(Phaser.Keyboard.TWO, changeState, 2);
    addKeyCallback(Phaser.Keyboard.THREE, changeState, 3);
    addKeyCallback(Phaser.Keyboard.FOUR, changeState, 4);
    addKeyCallback(Phaser.Keyboard.FIVE, changeState, 5);
    addKeyCallback(Phaser.Keyboard.SIX, changeState, 6);
    addKeyCallback(Phaser.Keyboard.SEVEN, changeState, 7);
    addKeyCallback(Phaser.Keyboard.EIGHT, changeState, 8);
    addKeyCallback(Phaser.Keyboard.NINE, changeState, 9);
    
}