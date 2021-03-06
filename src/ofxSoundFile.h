/*
 * ofxSoundFile.h
 *
 *  Created on: 25/07/2012
 *      Author: arturo
 */

#pragma once

#include "ofConstants.h"
#include "ofSoundBuffer.h"
#include "ofxAudioFile.h"
#include <sndfile.hh>
/// reads a sound file into an ofSoundBuffer.
/// encoding support varies by platform.
bool ofxLoadSound(ofSoundBuffer &buffer, std::string path);

/// writes an ofSoundBuffer as a 16-bit PCM WAV file.
bool ofxSaveSound(const ofSoundBuffer &buffer, std::string path);

class ofxSoundFile {
public:
	ofxSoundFile();
	ofxSoundFile(std::string path);

	void close();

	/// opens a sound file for reading with readTo().
	/// encoding support varies by platform.
	/// Windows and OSX use libaudiodecoder for decoding, Linux uses libsndfile
	bool load(std::string filepath);
	
	/// writes an ofSoundBuffer as a PCM WAV file
	/// Use any of the following values to set the file data format (Default is 16 bits)
	///
    ///	SF_FORMAT_PCM_S8			/* Signed 8 bit data */
	///	SF_FORMAT_PCM_16			/* Signed 16 bit data */
	///	SF_FORMAT_PCM_24			/* Signed 24 bit data */
	///	SF_FORMAT_PCM_32			/* Signed 32 bit data */
	///	SF_FORMAT_PCM_U8		/* Unsigned 8 bit data */

	static bool save(std::string _path, const ofSoundBuffer &buffer, int format = SF_FORMAT_PCM_16);

	
	/// reads a file into an ofSoundBuffer.
	/// by default, this will resize the buffer to fit the entire file.
	/// supplying a "samples" argument will read only the given number of samples
	void readTo(ofSoundBuffer &buffer, uint64_t samples = 0);
	
	/// returns sound file duration in milliseconds
	const uint64_t getDuration() const;
	const unsigned int getNumChannels() const;
	const unsigned int getSampleRate() const;
	const uint64_t getNumSamples() const;
	const bool isCompressed() const;
	const bool isLoaded() const;
	const std::string getPath() const;

private:
	
	ofxAudioFile audiofile;
	
	float duration; //in secs
	bool bCompressed;

};
