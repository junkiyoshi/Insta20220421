#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetCircleResolution(60);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = this->radius_list.size() - 1; i >= 0; i--) {

		this->radius_list[i] += this->speed_list[i];

		if (this->radius_list[i] > 450) {

			this->radius_list.erase(this->radius_list.begin() + i);
			this->speed_list.erase(this->speed_list.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	if (ofRandom(100) < 25) {

		this->radius_list.push_back(100);
		this->speed_list.push_back(ofRandom(0.5, 1.5));
	}

	ofFill();
	ofSetColor(0);
	ofDrawSphere(glm::vec3(), 100);

	for (auto& radius : this->radius_list) {

		auto alpha = radius < 300 ? 255 : ofMap(radius, 300, 450, 255, 0);

		ofNoFill();
		ofSetColor(255, alpha);
		ofDrawCircle(glm::vec3(), radius);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}