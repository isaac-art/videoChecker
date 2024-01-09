#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
        void draw();

        ofxJSONElement json;
        vector<string> videoPaths;
        vector<string> failedVideos;
        ofVideoPlayer videoPlayer;
        int currentVideoIndex = 0;
        float videoStartTime;

        void loadVideos();
        void playNextVideo();
        void logFailedVideo(string path);
		void printFailed();
		
};
