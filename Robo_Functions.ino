//Additional Functions

//Individual Motor Movement Functions
void moveForward_Left(){
    digitalWrite(L_FwdPin_1,HIGH);
    digitalWrite(L_BwdPin_2,LOW);
    digitalWrite(L_FwdPin_3,HIGH);
    digitalWrite(L_BwdPin_4,LOW);
}

void moveBackward_Left(){
    digitalWrite(L_FwdPin_1,LOW);
    digitalWrite(L_BwdPin_2,HIGH);
    digitalWrite(L_FwdPin_3,LOW);
    digitalWrite(L_BwdPin_4,HIGH);
}

void moveForward_Right(){
    digitalWrite(R_FwdPin_1,HIGH);
    digitalWrite(R_BwdPin_2,LOW);
    digitalWrite(R_FwdPin_3,HIGH);
    digitalWrite(R_BwdPin_4,LOW);
}

void moveBackward_Right(){
    digitalWrite(R_FwdPin_1,LOW);
    digitalWrite(R_BwdPin_2,HIGH);
    digitalWrite(R_FwdPin_3,LOW);
    digitalWrite(R_BwdPin_4,HIGH);
}

void stop_Right(){
    digitalWrite(R_FwdPin_1,LOW);
    digitalWrite(R_BwdPin_2,LOW);
    digitalWrite(R_FwdPin_3,LOW);
    digitalWrite(R_BwdPin_4,LOW);
}


void stop_Left(){
    digitalWrite(L_FwdPin_1,LOW);
    digitalWrite(L_BwdPin_2,LOW);
    digitalWrite(L_FwdPin_3,LOW);
    digitalWrite(L_BwdPin_4,LOW);
}

//==============================================


//Basic Movement Functions

void move_Forward(){
    moveForward_Left();
    moveForward_Right();
}

void move_Backward(){
    moveBackward_Left();
    moveBackward_Right();
}

void stop_Move(){
    stop_Left();
    stop_Right();
}

void rotate_Clockwise(){
    moveForward_Left();
    moveBackward_Right();
}

void rotate_CounterClockwise(){
    moveBackward_Left();
    moveForward_Right();
}

//==============================================
