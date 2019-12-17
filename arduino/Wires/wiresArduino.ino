void setup() {
  randomSeed(analogRead(0));
  int wireNum = 3+random(4);
  int cut;
  String wires[wireNum];
  String colours[] = {100,111,001,110,000};

   //randomise wires

  for (int i=0;i<wireNum;i++){
    wires[i] = colours[random(5)];      
  }

  //setup pins 
  // led: 0-6 left, 7-12 right rgb A0-2
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  for (int j=0;j<12;j++){
    digitalWrite(j,HIGH);    
  }  
  
  for (int i=0;i<wireNum;i++){
    for (int j=0;j<6;j++){
      if (int j==i){digitalWrite(j,LOW); digitalWrite(j+6,LOW);
      }else {digitalWrite(j,HIGH); digitalWrite(j+6,HIGH);}
    }
      
  }

   //compute the wire to cut

  switch(wireNum){
    case 3:
      if (countValue(wires,100,3)){cut=1;}
      else if (wires[2]==111){cut=2;}
      else if (countValue(wires,001,3)>1){cut=nthValue(wires,001,3,countValue(wires,001,3));}
      else{cut=2;}
    break;

    case 4:
      if (countValue(wires,100,4)>1&& random(2)>0.5){cut=nthValue(wires,100,3,countValue(wires,100,3));} //set serial num
      else if(wires[3]==110&&countValue(wires,100,4)==0){cut=0;}
      else if(countValue(wires,001,4)==1){cut=1;}
      else if(countValue(wires,110,4)>1){cut=3;}
      else{cut=1;}
    break;

    case 5:
      if (wires[4]=="black" && random(2)<0.5){cut=3;}//set serial
      else if(countValue(wires,100,5)==1 && countValue(wires,110,5)>1){cut=0;}
      else if(countValue(wires,"black",5)==0){cut=1;}
      else{cut=0;}
    break;

    case 6:
      if (countValue(wires,110,6)==0 && random(2)>0.5){cut=2;}
      else if (countValue(wires,110,6)==1&&countValue(wires,111,6)>1){cut=3;}
      else if (countValue(wires,100,6)){cut=5;}
      else{cut=3;}
    break;
  }

  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

int countValue(String Array[], String value, int aLength){
  int count=0;
  for(int i=0;i<aLength;i++){
    if (Array[i] == value){count++;}  
  }
  return count;
}

int nthValue(String Array[], String value, int aLength, int pos){
  int num = 0;
  for(int i=0;i<aLength;i++){
    if (Array[i] == value){
      num++;
    }    
    if (num == pos){
      return i;
    }
  }  
}
