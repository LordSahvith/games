demo.state1 = function(){};

var cursors;
var vel = 300;
var rocks;

demo.state1.prototype = {
    preload: function(){
        
        game.load.tilemap('field', '/tilemaps/state1.json', null, Phaser.Tilemap.TILED_JSON);
        game.load.image('grass', 'img/grass.png');
        game.load.image('flowers', 'img/flowers.png');
        game.load.image('rock', 'img/rock.png');
        
    },
    
    create: function(){
        
        addChangeStateEventListeners();
        
        game.world.setBounds(0, 0, 3200, 3200);
        
        var map = game.add.tilemap('field');
        map.addTilesetImage('grass');
        map.addTilesetImage('flowers');
        map.addTilesetImage('rock');
        
        var grass = map.createLayer('Tile Layer 1');  
        rocks = map.createLayer('rock'); 
        
        map.setCollisionBetween(3, 3, true, 'rock');
        
        me = game.add.sprite(200, 200, 'me');
        me.anchor.setTo(0.5, 0.5);
        me.scale.setTo(0.2, 0.2);
        game.physics.enable(me);        
        me.body.collideWorldBounds = true;        
        me.animations.add('walk', [0, 1, 2, 3, 4]);
        
        game.camera.follow(me);        
        game.camera.deadzone = new Phaser.Rectangle(centerX - 300, 200, 400, 400);
    },
    
    update: function(){
        
        game.physics.arcade.collide(me, rocks, function(){ console.log('hit rock'); });
        
        if(game.input.keyboard.isDown(Phaser.Keyboard.W)) {
            me.body.velocity.y = -vel;
            me.animations.play('walk', 10, true);
        } else if(game.input.keyboard.isDown(Phaser.Keyboard.S)) {
            me.body.velocity.y = vel;
            me.animations.play('walk', 10, true);
        } else if(game.input.keyboard.isDown(Phaser.Keyboard.A)) {
            me.scale.setTo(-0.2, 0.2);
            me.body.velocity.x = -vel;
            me.animations.play('walk', 10, true);
        } else if(game.input.keyboard.isDown(Phaser.Keyboard.D)) {
            me.scale.setTo(0.2, 0.2);
            me.body.velocity.x = vel;
            me.animations.play('walk', 10, true);
        } else {
            me.body.velocity.x = 0;
            me.body.velocity.y = 0;
            me.animations.stop();
            me.frame = 0;
        }
        
        
        
    }
};