
class Player {
	constructor(){
		this.xPosition = 0;
		this.yPosition = 0;
		this.angle = 0;
		this.direction = 0;
		this.velocity = 0;
		this.angleVelocity = 0;
		
		this.maxSpeed = 10;
		this.speed = 0.1;
		this.breaks = 0.1;
		this.size = 28;
		
		this.keys = {
			w: false,
			a: false,
			s: false,
			d: false,
			q: false,
			e: false
		}
	}
	draw(c){
		function xa(a) {
			return Math.sin(a * Math.PI / 180);
		}
		function ya(a) {
			return - Math.cos(a * Math.PI / 180);
		}
		
		let x = this.xPosition;
		let y = this.yPosition;
		let a = this.angle;
		let s = this.size;
		
		c.beginPath();
		
		c.moveTo(x + xa(a) * s, y + ya(a) * s);
		c.lineTo(x + xa(a + 2/5 * 360) * s, y + ya(a + 2/5 * 360) * s);
		c.lineTo(x + xa(a + 3/5 * 360) * s, y + ya(a + 3/5 * 360) * s);
		c.lineTo(x + xa(a) * s, y + ya(a) * s);
		
		c.fillStyle = '#fff';
		c.fill();
	}
	updatePosition() {
		function xa(a) {
			return Math.sin(a * Math.PI / 180);
		}
		function ya(a) {
			return -Math.cos(a * Math.PI / 180);
		}
		
		let d = this.direction;
		
		this.xPosition += this.velocity * xa(d);
		this.yPosition += this.velocity * ya(d);
		this.angle += this.angleVelocity;
	}
	updateControls() {
		
		this.velocity = Math.max(0, this.velocity - 0 * this.breaks);
		this.angleVelocity = 0;
		
		let keys = this.keys;
		
		if(keys.w && !keys.s) { // ir para frente
			this.velocity = Math.min(this.maxSpeed, this.velocity + this.speed);
			this.direction = this.direction - (this.direction - this.angle) * 0.01;
		}
		//if(keys.a && !keys.d) this.pos.vx = - this.speed;
		if(keys.s && !keys.w) this.velocity = Math.max(0, this.velocity - this.breaks); // ir para trás
		//if(keys.d && !keys.a) this.pos.vx = this.speed;
		if(keys.a && !keys.d) this.angleVelocity = - this.speed * this.size; // girar no sentido anti-horário
		if(keys.d && !keys.a) this.angleVelocity = this.speed * this.size; // girar no sentido horário
	}
      }
