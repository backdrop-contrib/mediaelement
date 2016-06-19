# Media Element

Media Element provides HTML5 video and audio elements by using
mediaelement.js . This is a jQuery based JavaScript plugin that
enables the video and audio tags using h.264 to work under browsers
that do not support the tag or the codec and provides a consistent
interface across all browsers.

This is a port from the Drupal module of the same name, version 7.x-1.2

## Status

This is a working port but please report any problems.


## Installation

- Download MediaElement from http://mediaelementjs.com/

- Unzip into a libraries directory supported by the libraries module
  with the name mediaelement (e.g., libraries/mediaelement). Note
  that the essential library files are in subdirectory /build
  i.e. libraries/mediaelement/build

- Install the libraries and mediaelement modules using the official
  Backdrop CMS instructions at https://backdropcms.org/guide/modules

- Use the configuration page at /admin/config/media/mediaelement to
  check that the library is working and optionally to
  enable mediaelement.js site wide.

## Usage example

- Add a field of type file to your content type, making sure that
  upload of an appropriate file type is allowed e.g. mp3

- Configure the display settings for this field (using Manage Display),
  selecting the format MediaElement Audio or MediaElement Video as appropriate.

- Adjust the width and height format settings if necessary.



## License

This project is GPL v2 software. See the LICENSE.txt 
file in this directory for complete text.
    
## Ported to Backdrop

Graham Oliver (github.com/Graham-72/)


## Credits

### Maintainers for Drupal:

- Dave Reid
- Matt Farina (mfer)

### Acknowledgement

This port to Backdrop would not, of course, be possible without all
the work done by the developers and maintainers of the Drupal module.

