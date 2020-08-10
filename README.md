# UnSoundBoard
A clean soundboard application built in Unreal Engine 4.

<img src="./Screenshots/USB Screenshot v1.0.0.JPG"  width="66%">

## Description

I wanted to use a soundboard application to play sounds through a virtual microphone while playing D&D online with friends, but I couldn't find one that I liked. Most of the soundboards looked ugly, limited the number of sounds you could use or see, and critically, would not have any randomization of the sounds played.

So I made this project to address those issues. UnSoundBoard looks clean, it resizes based on the window size, and it allows you to randomly play a sound from many in a particular folder when selecting the soundboard button for that folder. 

## Usage
1. Open UnSoundBoard.exe
1. Enter the file path to your sounds folder in the text box. This path should be a folder that only contains subfolders which in turn only contain the sound files you want to play. Other setups are not tested yet and may or may not work (probably not).
1. Hit the "Reload Sounds" button. If you set up your folders correctly, each subfolder will be added as a button to the centre of the UI, organized alphabetically by name (you may wish to add numbers or similar markers to the starts of your folder names to specify their orders). If not, reread the above step.
1. Click on one of the buttons and (hopefully) one of the sounds from that folder, chosen randomly, should play.

To use UnSoundBoard, the main requirement is careful folder organization of the sounds you wish to play. For example, consider the following valid folder structure:
```
- C:/Path/To/My/Sounds
    - 1 Dog
        - Woof.mp3
        - Bark.wav
    - 2 Cat
        - Meow.wav
        - Purr.wav
    - 3 Bird
        - Chirp.mp3
```
This directory structure is valid, because our sounds folder (`C:/Path/To/My/Sounds`) contains only folders (`1 Dog`, `2 Cat`, `3 Bird`) which contain only playable sound files (`*.wav`, `*.mp3`). The user would enter `C:/Path/To/My/Sounds` into the text box in UnSoundBoard, and UnSoundBoard would create three sound cue buttons `1 Dog`, `2 Cat`, and `3 Bird`. Clicking on, say the `2 Cat` button, would play either `C:/Path/To/My/Sounds/2 Cat/Meow.wav` or `C:/Path/To/My/Sounds/2 Cat/Purr.wav` randomly.

## Known Issues:
* Currently only Windows is being tested and built for. This may or may not work for other platforms, but you would have to clone the Unreal project and repackage it yourself to get an executable.
* This uses Unreal Engine's [Media Player API](https://docs.unrealengine.com/en-US/Engine/MediaFramework/TechReference/index.html), so it only supports the file types which that supports. I've tested it with .wav and .mp3 files on Windows 10, and it may work for other file types (probably .ogg), but it's platform-dependent and not guaranteed.
* Currently, there is no option to play audio to a specific output device. This is a very important feature for an application like this (such that one might send its output to a virtual microphone input for use over voice chat applications), and it will come in a future release. As a workaround for now, in Windows, you can edit "App volume device preferences" in your settings which will let you choose the default output device for UnSoundBoard specifically (UnSoundBoard must be open for this to take effect).
* Currently, only one sound can be playing at a time. This means if you press a button to play a sound and then press another button to play another sound, the first sound will be cut off. A fix for this is coming very soon.
