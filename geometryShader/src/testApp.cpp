#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(50, 50, 50);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	
	shader.setGeometryInputType(GL_LINES);
	shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
	shader.setGeometryOutputCount(4);
	shader.load("shaders/vert.glsl", "shaders/frag.glsl", "shaders/geom.glsl"); 
	
	printf("Maximum number of output vertices support is: %i\n", shader.getGeometryMaxOutputCount());
	
	// create a bunch of random points
	float r = ofGetHeight()/2;
	for(int i=0; i<70; i++) {
		pointsT.push_back(ofPoint(i*20, 20, 1));
	}
    
    for(int i=0; i<70; i++) {
		pointsB.push_back(ofPoint(i*20, 748, 1));
	}
    
	doShader = true;	
	glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();

    //glScalef(.5,.5,1);

    cam.begin();

	if(doShader) {

		shader.begin();

		// set thickness of ribbons
		shader.setUniform1f("thickness", 5);
		
		// make light direction slowly rotate
		// shader.setUniform3f("lightDir", sin(ofGetElapsedTimef()), cos(ofGetElapsedTimef()), 0);
        
        shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
        shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
        
        //we also pass in the mouse position 
        //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped. 
        shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );

	}

	//glColor3f(1, 1, 1);
	
	ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 0);
    
    // draw our array of geom
	for(int i=1; i<pointsT.size(); i++) {
		ofLine(pointsT[i], pointsB[i]);
	}
    
    cam.end();

	if(doShader) shader.end();
	
	ofPopMatrix();
	
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()) + "\nPress 's' to toggle shader: " + (doShader ? "ON" : "OFF"), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}

