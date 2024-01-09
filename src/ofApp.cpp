#include "ofApp.h"


void ofApp::setup(){
    // Load JSON file
    if(json.open("mp4_files_list.json")){
        for(Json::ArrayIndex i = 0; i < json.size(); ++i){
            videoPaths.push_back(json[i].asString());
        }
    }

    loadVideos();
}

void ofApp::loadVideos(){
    if(videoPaths.size() > 0){
        playNextVideo();
    }
}

void ofApp::playNextVideo(){
    if(currentVideoIndex < videoPaths.size()){
        if(videoPlayer.load(videoPaths[currentVideoIndex])){
            videoPlayer.play();
            cout << "Playing " << videoPaths[currentVideoIndex] << endl;
            videoStartTime = ofGetElapsedTimef();
        } else {
            logFailedVideo(videoPaths[currentVideoIndex]);
            currentVideoIndex++;
            playNextVideo();
        }
    }else{
        printFailed();
    }
}

void ofApp::update(){
    videoPlayer.update();
    if(ofGetElapsedTimef() - videoStartTime > 5){
        currentVideoIndex++;
        playNextVideo();
    }
}

void ofApp::draw(){
    if(videoPlayer.isLoaded()){
        videoPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
}

void ofApp::logFailedVideo(string path){
    cout << "Failed to load " << path << endl;
    failedVideos.push_back(path);
}

void ofApp::printFailed(){
    if(failedVideos.size() > 0){
        cout << "Failed Videos:" << endl;
        for(string failedVideo : failedVideos){
            cout << failedVideo << endl;
        }
    } else {
        cout << "No failed videos." << endl;
    }
    // exit the program
    ofExit();
}