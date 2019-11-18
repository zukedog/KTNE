int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 1000;
float R2= 0;
float buffer= 0;

bool serialOdd=true;

const int RED = 0;
const int WHITE = 1;
const int BLUE = 2;
const int YELLOW = 3;
const int BLACK = 4;

void setup() {
  Serial.begin(9600);
  int wires[6];
  for(int i=0; i<6; i++){
    wires[i]=gameRead(i);
    Serial.println(wires[i]);
  }
  Serial.println(" ");
  Serial.println(gameCheck(wires));
}

void loop() {
 
}

int gameCheck(int wires[]){
  switch (count(wires,5,6)){
    case 0:
      return check6(wires);
    break;
    case 1:
      return check5(wires);
    break;
    case 2:
      return check4(wires);
    break;
    case 3:
      return check3(wires);
    break;
    
  }
}

int check3(int wires[]){
  if (count(wires,RED,6)<1){
    return 2;
  }else if(wires[6]==WHITE){
    return 3;
  }else if(count(wires,BLUE,6)>1){
    for (int i=5;i>=0;i--){
      if(wires[i]==BLUE){
       return i;
       break;
      }
    }
  }else{
    return 3;
  }
}

bool check4(int wires[]){
  
}

bool check5(int wires[]){

}

bool check6(int wires[]){

}

int count(int in[],int selector,int leng){
  int success=0;
  for (int i=0;i<leng;i++){
    if(in[i]==selector){
      success++;
    }
  }
  return success;
}

int gameRead(int pin){
  raw=analogRead(pin);
    if(raw) {
      buffer= raw * Vin;
      Vout= (buffer)/1024.0;
      buffer= (Vin/Vout) -1;
      R2= R1 * buffer;
      return type(R2);
    }
    return 5;
}

int type(float R){
  if(R < 200){
    return 0;
  }
  if(R < 405){
    return 1;
  }
  if(R < 10000){
    return 2;
  }
  if (R < 335000){
    return 3;
  }
  return 4;
}
