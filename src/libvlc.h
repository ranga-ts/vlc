/*****************************************************************************
 * libvlc.h: main libvlc header
 *****************************************************************************
 * Copyright (C) 1998-2002 VideoLAN
 * $Id: libvlc.h,v 1.105 2003/11/14 20:17:29 hartman Exp $
 *
 * Authors: Vincent Seguin <seguin@via.ecp.fr>
 *          Samuel Hocevar <sam@zoy.org>
 *          Gildas Bazin <gbazin@netcourrier.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

#define Nothing here, this is just to prevent update-po from being stupid
#include "vlc_keys.h"

static char *ppsz_language[] =
{ "auto", "en", "en_GB", "es", "de",
  "fr", "hu", "it", "ja", "nl", "no",
  "pl", "pt_BR", "ru", "sv" };
static char *ppsz_language_text[] =
{ N_("Auto"), N_("English US"), N_("English GB"), N_("Spanish"), N_("German"),
  N_("French"), N_("Hungarian"), N_("Italian"), N_("Japanese"), N_("Dutch"), N_("Norwegian"),
  N_("Polish"), N_("Portuguese BR"), N_("Russian"), N_("Swedish") };

/*****************************************************************************
 * Configuration options for the main program. Each module will also separatly
 * define its own configuration options.
 * Look into configuration.h if you need to know more about the following
 * macros.
 *****************************************************************************/

#define INTF_CAT_LONGTEXT N_( \
    "These options allow you to configure the interfaces used by VLC.\n" \
    "You can select the main interface, additional " \
    "interface modules, and define various related options." )

#define INTF_TEXT N_("Interface module")
#define INTF_LONGTEXT N_( \
    "This option allows you to select the interface used by VLC.\n" \
    "The default behavior is to automatically select the best module " \
    "available.")

#define EXTRAINTF_TEXT N_("Extra interface modules")
#define EXTRAINTF_LONGTEXT N_( \
    "This option allows you to select additional interfaces used by VLC. " \
    "They will be launched in the background in addition to the default " \
    "interface. Use a comma separated list of interface modules. (common " \
    "values are: logger,gestures,sap,rc,http,screensaver)")

#define VERBOSE_TEXT N_("Verbosity (0,1,2)")
#define VERBOSE_LONGTEXT N_( \
    "This options sets the verbosity level (0=only errors and " \
    "standard messages, 1=warnings, 2=debug).")

#define QUIET_TEXT N_("Be quiet")
#define QUIET_LONGTEXT N_( \
    "This options turns off all warning and information messages.")

#define LANGUAGE_TEXT N_("Language")
#define LANGUAGE_LONGTEXT N_( "This option allows you to set the language " \
    "of the interface. The system language is auto-detected if \"auto\" is " \
    "specified here." )

#define COLOR_TEXT N_("Color messages")
#define COLOR_LONGTEXT N_( \
    "When this option is turned on, the messages sent to the console will " \
    "be colorized. Your terminal needs Linux color support for this to work.")

#define ADVANCED_TEXT N_("Show advanced options")
#define ADVANCED_LONGTEXT N_( \
    "When this option is turned on, the preferences and/or interfaces  will " \
    "show all the available options, including those that most users should " \
    "never touch")

#define INTF_PATH_TEXT N_("Interface default search path")
#define INTF_PATH_LONGTEXT N_( \
    "This option allows you to set the default path that the interface will " \
    "open when looking for a file.")

#define PLUGIN_PATH_TEXT N_("Plugin search path")
#define PLUGIN_PATH_LONGTEXT N_( \
    "This option allows you to specify an additional path for VLC to look " \
    "for its plugins.")

#define AOUT_CAT_LONGTEXT N_( \
    "These options allow you to tune VLC's audio subsystem, " \
    "and to add audio filters which can be used for " \
    "postprocessing or visual effects (spectrum analyser,...).\n" \
    "To tune these filters, have a look at the \"audio filter\" " \
    "plugin options.")

#define AOUT_TEXT N_("Audio output module")
#define AOUT_LONGTEXT N_( \
    "This option allows you to select the audio output method used by VLC. " \
    "The default behavior is to automatically select the best method " \
    "available.")

#define AUDIO_TEXT N_("Enable audio")
#define AUDIO_LONGTEXT N_( \
    "You can completely disable the audio output. In this case the audio " \
    "decoding will not take place, and it will save some processing power.")

#define MONO_TEXT N_("Force mono audio")
#define MONO_LONGTEXT N_("This will force a mono audio output")

#define VOLUME_TEXT N_("Audio output volume")
#define VOLUME_LONGTEXT N_( \
    "You can set the default audio output volume here, in a range from 0 to " \
    "1024.")

#define VOLUME_SAVE_TEXT N_("Audio output saved volume")
#define VOLUME_SAVE_LONGTEXT N_( \
    "This saves the audio output volume when you select mute.")

#define AOUT_RATE_TEXT N_("Audio output frequency (Hz)")
#define AOUT_RATE_LONGTEXT N_( \
    "You can force the audio output frequency here. Common values are " \
    "-1 (default), 48000, 44100, 32000, 22050, 16000, 11025, 8000.")

#if !defined( SYS_DARWIN )
#define AOUT_RESAMP_TEXT N_("High quality audio resampling")
#define AOUT_RESAMP_LONGTEXT N_( \
    "High quality audio resampling can be processor intensive so you can " \
    "disable it and a cheaper resampling algorithm will be used instead.")
#endif

#define DESYNC_TEXT N_("Compensate desynchronization of audio (in ms)")
#define DESYNC_LONGTEXT N_( \
    "This option allows you to delay the audio output. This can be handy if " \
    "you notice a lag between the video and the audio.")

#define MULTICHA_TEXT N_("Choose prefered audio output channels mode")
#define MULTICHA_LONGTEXT N_( \
    "This option allows you to set the audio output channels mode that will " \
    "be used by default when possible (ie. if your hardware supports it as " \
    "well as the audio stream being played)")

#define SPDIF_TEXT N_("Use the S/PDIF audio output when available")
#define SPDIF_LONGTEXT N_( \
    "This option allows you to use the S/PDIF audio output by default when " \
    "your hardware supports it as well as the audio stream being played.")

#define AUDIO_FILTER_TEXT N_("Audio filters")
#define AUDIO_FILTER_LONGTEXT N_( \
    "This allows you to add audio postprocessing filters, to modify " \
    "the sound.")

#define HEADPHONE_TEXT N_("Headphone virtual spatialization effect")
#define HEADPHONE_LONGTEXT N_( \
    "This effect gives you the feeling that you are standing in a room " \
    "with a complete 5.1 speaker set when using only a headphone, " \
    "providing a more realistic sound experience. It should also be " \
    "more comfortable and less tiring when listening to music for " \
    "long periods of time.\nIt works with any source format from mono " \
    "to 5.1.")

#define VOUT_CAT_LONGTEXT N_( \
    "These options allow you to modify options related to " \
    "the video output subsystem. You can for example enable " \
    "video filters, like deinterlacing, constrast / hue / " \
    "saturation adjusting, ...\n" \
    "Enable these filters here and configure them in the video " \
    "filters plugins section." )

#define VOUT_TEXT N_("Video output module")
#define VOUT_LONGTEXT N_( \
    "This option allows you to select the video output method used by VLC. " \
    "The default behavior is to automatically select the best " \
    "method available.")

#define VIDEO_TEXT N_("Enable video")
#define VIDEO_LONGTEXT N_( \
    "You can completely disable the video output. In this case the video " \
    "decoding stage will not take place, which will save some processing power.")

#define WIDTH_TEXT N_("Video width")
#define WIDTH_LONGTEXT N_( \
    "You can enforce the video width here. By default (-1) VLC will " \
    "adapt to the video characteristics.")

#define HEIGHT_TEXT N_("Video height")
#define HEIGHT_LONGTEXT N_( \
    "You can enforce the video height here. By default (-1) VLC will " \
    "adapt to the video characteristics.")

#define ALIGN_TEXT N_("Video alignment")
#define ALIGN_LONGTEXT N_( \
    "You can enforce the video alignement in its window. By default (0) it " \
    "will be centered (0=center, 1=left, 2=right, 4=top, 8=bottom, you can " \
    "also use combinations of these values).")

#define ZOOM_TEXT N_("Zoom video")
#define ZOOM_LONGTEXT N_( \
    "You can zoom the video by the specified factor.")

#define GRAYSCALE_TEXT N_("Grayscale video output")
#define GRAYSCALE_LONGTEXT N_( \
    "When enabled, the color information from the video won't be decoded " \
    "(this can also allow you to save some processing power).")

#define FULLSCREEN_TEXT N_("Fullscreen video output")
#define FULLSCREEN_LONGTEXT N_( \
    "If this option is enabled, VLC will always start a video in fullscreen " \
    "mode.")

#define OVERLAY_TEXT N_("Overlay video output")
#define OVERLAY_LONGTEXT N_( \
    "If enabled, VLC will try to take advantage of the overlay capabilities " \
    "of your graphics card.")

#define SPUMARGIN_TEXT N_("Force SPU position")
#define SPUMARGIN_LONGTEXT N_( \
    "You can use this option to place the subtitles under the movie, " \
    "instead of over the movie. Try several positions.")

#define OSD_TEXT N_("On Screen Display")
#define OSD_LONGTEXT N_( \
    "You can disable the messages VLC creates in the video.")

#define FILTER_TEXT N_("Video filter module")
#define FILTER_LONGTEXT N_( \
    "This will allow you to add a post-processing filter to enhance the " \
    "picture quality, for instance deinterlacing, or to clone or distort " \
    "the video window.")

#define ASPECT_RATIO_TEXT N_("Source aspect ratio")
#define ASPECT_RATIO_LONGTEXT N_( \
    "This will force the source aspect ratio. For instance, some DVDs claim " \
    "to be 16:9 while they are actually 4:3. This can also be used as a " \
    "hint for VLC when a movie does not have aspect ratio information. " \
    "Accepted formats are x:y (4:3, 16:9, etc.) expressing the global image " \
    "aspect, or a float value (1.25, 1.3333, etc.) expressing pixel " \
    "squareness.")

#if 0
#define PIXEL_RATIO_TEXT N_("Destination aspect ratio")
#define PIXEL_RATIO_LONGTEXT N_( \
    "This will force the destination pixel size. By default VLC assumes " \
    "your pixels are square, unless your hardware has a way to tell it " \
    "otherwise. This may be used when you output VLC's signal to another " \
    "device such as a TV set. Accepted format is a float value (1, 1.25, " \
    "1.3333, etc.) expressing pixel squareness.")
#endif

#define INPUT_CAT_LONGTEXT N_( " " )

#define SERVER_PORT_TEXT N_("Server port")
#define SERVER_PORT_LONGTEXT N_( \
    "This is the port used for UDP streams. By default, we chose 1234.")

#define MTU_TEXT N_("MTU of the network interface")
#define MTU_LONGTEXT N_( \
    "This is the typical size of UDP packets that we expect. On Ethernet " \
    "it is usually 1500.")

#define IFACE_ADDR_TEXT N_("Network interface address")
#define IFACE_ADDR_LONGTEXT N_( \
    "If you have several interfaces on your machine and use the " \
    "multicast solution, you will probably have to indicate the IP address " \
    "of your multicasting interface here.")

#define TTL_TEXT N_("Time to live")
#define TTL_LONGTEXT N_( \
    "Indicate here the Time To Live of the multicast packets sent by " \
    "the stream output.")

#define INPUT_PROGRAM_TEXT N_("Choose program (SID)")
#define INPUT_PROGRAM_LONGTEXT N_( \
    "Choose the program to select by giving its Service ID.")

#define INPUT_AUDIO_TEXT N_("Choose audio")
#define INPUT_AUDIO_LONGTEXT N_( \
    "Give the default type of audio you want to use in a DVD. " \
    "(Developers only)")

#define INPUT_CHAN_TEXT N_("Choose channel")
#define INPUT_CHAN_LONGTEXT N_( \
    "Give the stream number of the audio channel you want to use in a DVD " \
    "(from 1 to n).")

#define INPUT_SUBT_TEXT N_("Choose subtitles track")
#define INPUT_SUBT_LONGTEXT N_( \
    "Give the stream number of the subtitle channel you want to use " \
    "(from 1 to n).")

#define SUB_AUTO_TEXT N_("Autodetect subtitle files")
#define SUB_AUTO_LONGTEXT \
    "Automatically detect a subtitle file, if no subtitle filename is " \
    "specified."

#define SUB_FUZZY_TEXT N_("Subtitle autodection fuzziness")
#define SUB_FUZZY_LONGTEXT \
    "This determines how fuzzy subtitle and movie filenaming matching " \
    "will be. Options are:\n" \
    "0 = no subtitles autodetected\n" \
    "1 = any subtitle file\n" \
    "2 = any subtitle file containing the movie name\n" \
    "3 = subtitle file matching the movie name with additional chars\n" \
    "4 = subtitle file matching the movie name exactly"

#define SUB_FILE_TEXT N_("Use subtitle file")
#define SUB_FILE_LONGTEXT \
    "Load this subtitle file. To be used when autodetect cannot detect " \
    "your subtitlefile."

#define DVD_DEV_TEXT N_("DVD device")
#ifdef WIN32
#define DVD_DEV_LONGTEXT N_( \
    "This is the default DVD drive (or file) to use. Don't forget the colon " \
    "after the drive letter (eg D:)")
#else
#define DVD_DEV_LONGTEXT N_( \
    "This is the default DVD device to use.")
#endif

#define VCD_DEV_TEXT N_("VCD device")
#define VCD_DEV_LONGTEXT N_( \
    "This is the default VCD device to use.")

#define IPV6_TEXT N_("Force IPv6")
#define IPV6_LONGTEXT N_( \
    "If you check this box, IPv6 will be used by default for all UDP and " \
    "HTTP connections.")

#define IPV4_TEXT N_("Force IPv4")
#define IPV4_LONGTEXT N_( \
    "If you check this box, IPv4 will be used by default for all UDP and " \
    "HTTP connections.")

#define CODEC_CAT_LONGTEXT N_( \
    "This option can be used to alter the way VLC selects " \
    "its codecs (decompression methods). Only advanced users should " \
    "alter this option as it can break playback of all your streams." )

#define CODEC_TEXT N_("Choose preferred codec list")
#define CODEC_LONGTEXT N_( \
    "This allows you to select the order in which VLC will choose its " \
    "codecs. For instance, 'a52old,a52,any' will try the old a52 codec " \
    "before the new one. Please be aware that VLC does not make any " \
    "difference between audio or video codecs, so you should always specify " \
    "'any' at the end of the list to make sure there is a fallback for the " \
    "types you didn't specify.")


#define ENCODER_VIDEO_TEXT N_("Choose preferred video encoder list")
#define ENCODER_VIDEO_LONGTEXT N_( \
    "This allows you to select the order in which VLC will choose its " \
    "codecs. " )
#define ENCODER_AUDIO_TEXT N_("Choose preferred audio encoder list")
#define ENCODER_AUDIO_LONGTEXT N_( \
    "This allows you to select the order in which VLC will choose its " \
    "codecs. " )

#define SOUT_CAT_LONGTEXT N_( \
    "These options allow you to set default global options for the " \
    "stream output subsystem." )

#define SOUT_TEXT N_("Choose a stream output")
#define SOUT_LONGTEXT N_( \
    "Empty if no stream output.")

#define SOUT_DISPLAY_TEXT N_("Display while streaming")
#define SOUT_DISPLAY_LONGTEXT N_( \
    "This allows you to play the stream while streaming it.")

#define SOUT_VIDEO_TEXT N_("Enable video stream output")
#define SOUT_VIDEO_LONGTEXT N_( \
    "This allows you to choose if the video stream should be redirected to " \
    "the stream output facility when this last one is enabled.")

#define SOUT_AUDIO_TEXT N_("Enable audio stream output")
#define SOUT_AUDIO_LONGTEXT N_( \
    "This allows you to choose if the video stream should be redirected to " \
    "the stream output facility when this last one is enabled.")

#define SOUT_KEEP_TEXT N_("Keep sout open" )
#define SOUT_KEEP_LONGTEXT N_( \
    "This allows you to keep an unique sout instance across " \
    "multiple playlist item (automatically insert gather stream_out " \
    "if not specified)" )

#define PACKETIZER_TEXT N_("Choose preferred packetizer list")
#define PACKETIZER_LONGTEXT N_( \
    "This allows you to select the order in which VLC will choose its " \
    "packetizers."  )

#define MUX_TEXT N_("Mux module")
#define MUX_LONGTEXT N_( \
    "This is a legacy entry to let you configure mux modules")

#define ACCESS_OUTPUT_TEXT N_("Access output module")
#define ACCESS_OUTPUT_LONGTEXT N_( \
    "This is a legacy entry to let you configure access output modules")

#define CPU_CAT_LONGTEXT N_( \
    "These options allow you to enable special CPU optimizations.\n" \
    "You should always leave all these enabled." )

#define MMX_TEXT N_("Enable CPU MMX support")
#define MMX_LONGTEXT N_( \
    "If your processor supports the MMX instructions set, VLC can take " \
    "advantage of them.")

#define THREE_DN_TEXT N_("Enable CPU 3D Now! support")
#define THREE_DN_LONGTEXT N_( \
    "If your processor supports the 3D Now! instructions set, VLC can take " \
    "advantage of them.")

#define MMXEXT_TEXT N_("Enable CPU MMX EXT support")
#define MMXEXT_LONGTEXT N_( \
    "If your processor supports the MMX EXT instructions set, VLC can take " \
    "advantage of them.")

#define SSE_TEXT N_("Enable CPU SSE support")
#define SSE_LONGTEXT N_( \
    "If your processor supports the SSE instructions set, VLC can take " \
    "advantage of them.")

#define ALTIVEC_TEXT N_("Enable CPU AltiVec support")
#define ALTIVEC_LONGTEXT N_( \
    "If your processor supports the AltiVec instructions set, VLC can take " \
    "advantage of them.")

#define PLAYLIST_CAT_LONGTEXT N_( \
     "These options define the behaviour of the playlist. Some " \
     "of them can be overriden in the playlist dialog box." ) 

#define RANDOM_TEXT N_("Play files randomly forever")
#define RANDOM_LONGTEXT N_( \
    "When selected, VLC will randomly play files in the playlist until " \
    "interrupted.")

#define LOOP_TEXT N_("Loop playlist on end")
#define LOOP_LONGTEXT N_( \
    "If you want VLC to keep playing the playlist indefinitely then enable " \
    "this option.")
    
#define REPEAT_TEXT N_("Repeat the current playlistitem")
#define REPEAT_LONGTEXT N_( \
    "When this is active VLC will keep playing the current playlistitem " \
    "over and over again.")

#define MISC_CAT_LONGTEXT N_( \
    "These options allow you to select default modules. Leave these " \
    "alone unless you really know what you are doing." )

#define MEMCPY_TEXT N_("Memory copy module")
#define MEMCPY_LONGTEXT N_( \
    "You can select which memory copy module you want to use. By default " \
    "VLC will select the fastest one supported by your hardware.")

#define ACCESS_TEXT N_("Access module")
#define ACCESS_LONGTEXT N_( \
    "This is a legacy entry to let you configure access modules")

#define DEMUX_TEXT N_("Demux module")
#define DEMUX_LONGTEXT N_( \
    "This is a legacy entry to let you configure demux modules")

#define RT_PRIORITY_TEXT N_("Allow VLC to run with a real-time priority")
#define RT_PRIORITY_LONGTEXT N_( \
    "Running VLC in real-time priority will allow for much more precise " \
    "scheduling and yield better, especially when streaming content. " \
    "It can however lock up your whole machine, or make it very very " \
    "slow. You should only activate this if you know what you're " \
    "doing.")

#define ONEINSTANCE_TEXT N_("Allow only one running instance of VLC")
#define ONEINSTANCE_LONGTEXT N_( \
    "Allowing only one running instance of VLC can sometimes be useful, " \
    "for instance if you associated VLC with some media types and you " \
    "don't want a new instance of VLC to be opened each time you " \
    "double-click on a file in the explorer. This option will allow you " \
    "to play the file with the already running instance or enqueue it.")

#define HPRIORITY_TEXT N_("Increase the priority of the process")
#define HPRIORITY_LONGTEXT N_( \
    "Increasing the priority of the process will very likely improve your " \
    "playing experience as it allows VLC not to be disturbed by other " \
    "applications that could otherwise take too much processor time.\n" \
    "However be advise that in certain circumstances (bugs) VLC could take " \
    "all the processor time and render the whole system unresponsive which " \
    "might require a reboot of your machine.")

#define FAST_MUTEX_TEXT N_("Fast mutex on NT/2K/XP (developers only)")
#define FAST_MUTEX_LONGTEXT N_( \
    "On Windows NT/2K/XP we use a slow mutex implementation but which " \
    "allows us to correctely implement condition variables. " \
    "You can also use the faster Win9x implementation but you might " \
    "experience problems with it.")

#define WIN9X_CV_TEXT N_("Condition variables implementation for Win9x " \
    "(developers only)")
#define WIN9X_CV_LONGTEXT N_( \
    "On Windows 9x/Me we use a fast but not correct condition variables " \
    "implementation (more precisely there is a possibility for a race " \
    "condition to happen). " \
    "However it is possible to use slower alternatives which should be more " \
    "robust. " \
    "Currently you can choose between implementation 0 (which is the " \
    "default and the fastest), 1 and 2.")

#define HOTKEY_CAT_LONGTEXT N_( " " )

#define FULLSCREEN_KEY_TEXT N_("Fullscreen")
#define FULLSCREEN_KEY_LONGTEXT N_("Select the hotkey to use to swap fullscreen state")
#define PLAY_PAUSE_KEY_TEXT N_("Play/ause")
#define PLAY_PAUSE_KEY_LONGTEXT N_("Select the hotkey to use to swap paused state")
#define PAUSE_KEY_TEXT N_("Pause only")
#define PAUSE_KEY_LONGTEXT N_("Select the hotkey to use to pause")
#define PLAY_KEY_TEXT N_("Play only")
#define PLAY_KEY_LONGTEXT N_("Select the hotkey to use to play")
#define FASTER_KEY_TEXT N_("Faster")
#define FASTER_KEY_LONGTEXT N_("Select the hotkey to use for fast forward playback")
#define SLOWER_KEY_TEXT N_("Slower")
#define SLOWER_KEY_LONGTEXT N_("Select the hotkey to use for slow motion playback")
#define NEXT_KEY_TEXT N_("Next")
#define NEXT_KEY_LONGTEXT N_("Select the hotkey to use to skip to the next item in the playlist")
#define PREV_KEY_TEXT N_("Previous")
#define PREV_KEY_LONGTEXT N_("Select the hotkey to use to skip to the previous item in the playlist")
#define STOP_KEY_TEXT N_("Stop")
#define STOP_KEY_LONGTEXT N_("Select the hotkey to stop the playback")

#define JB10SEC_KEY_TEXT N_("Jump backward 10 seconds")
#define JB10SEC_KEY_LONGTEXT N_("Select the hotkey to jump backward by 10 seconds")

#define JB1MIN_KEY_TEXT N_("Jump backward 1 minute")
#define JB1MIN_KEY_LONGTEXT N_("Select the hotkey to jump backward by 1 minute")
#define JB5MIN_KEY_TEXT N_("Jump backward 5 minutes")
#define JB5MIN_KEY_LONGTEXT N_("Select the hotkey to jump backward by 5 minutes")
#define JF10SEC_KEY_TEXT N_("Jump forward 10 seconds")
#define JF10SEC_KEY_LONGTEXT N_("Select the hotkey to jump forward by 10 seconds")

#define JF1MIN_KEY_TEXT N_("Jump forward 1 minute")
#define JF1MIN_KEY_LONGTEXT N_("Select the hotkey to jump forward by 1 minute")

#define JF5MIN_KEY_TEXT N_("Jump forward 5 minutes")
#define JF5MIN_KEY_LONGTEXT N_("Select the hotkey to jump forward by 5 minutes")

#define QUIT_KEY_TEXT N_("Quit")
#define QUIT_KEY_LONGTEXT N_("Select the hotkey to quit the application")
#define NAV_UP_KEY_TEXT N_("Navigate up")
#define NAV_UP_KEY_LONGTEXT N_("Select the key to move the selector up in dvd menus")
#define NAV_DOWN_KEY_TEXT N_("Navigate down")
#define NAV_DOWN_KEY_LONGTEXT N_("Select the key to move the selector down in dvd menus")
#define NAV_LEFT_KEY_TEXT N_("Navigate left")
#define NAV_LEFT_KEY_LONGTEXT N_("Select the key to move the selector left in dvd menus")
#define NAV_RIGHT_KEY_TEXT N_("Navigate right")
#define NAV_RIGHT_KEY_LONGTEXT N_("Select the key to move the selector right in dvd menus")
#define NAV_ACTIVATE_KEY_TEXT N_("Activate")
#define NAV_ACTIVATE_KEY_LONGTEXT N_("Select the key to activate selected item in dvd menus")
#define VOL_UP_KEY_TEXT N_("Volume up")
#define VOL_UP_KEY_LONGTEXT N_("Select the key to turn up audio volume")
#define VOL_DOWN_KEY_TEXT N_("Volume down")
#define VOL_DOWN_KEY_LONGTEXT N_("Select the key to turn down audio volume")

#define PLAYLIST_USAGE N_("\nPlaylist items:" \
    "\n  *.mpg, *.vob                   plain MPEG-1/2 files" \
    "\n  [dvd:][device][@raw_device][@[title][,[chapter][,angle]]]" \
    "\n                                 DVD device" \
    "\n  [vcd:][device][@[title][,[chapter]]" \
    "\n                                 VCD device" \
    "\n  udpstream:[@[<bind address>][:<bind port>]]" \
    "\n                                 UDP stream sent by a streaming server" \
    "\n  vlc:pause                      pause execution of " \
    "playlist items" \
    "\n  vlc:quit                       quit VLC" \
    "\n")


/*
 * Quick usage guide for the configuration options:
 *
 * add_category_hint( N_(text), N_(longtext) );
 * add_subcategory_hint( N_(text), N_(longtext) );
 * add_usage_hint( N_(text) );
 * add_string( option_name, value, p_callback, N_(text), N_(longtext) );
 * add_file( option_name, psz_value, p_callback, N_(text), N_(longtext) );
 * add_module( option_name, psz_value, i_capability, p_callback,
 *             N_(text), N_(longtext) );
 * add_integer( option_name, i_value, p_callback, N_(text), N_(longtext) );
 * add_bool( option_name, b_value, p_callback, N_(text), N_(longtext) );
 */

vlc_module_begin();
    /* Interface options */
    add_category_hint( N_("Interface"), INTF_CAT_LONGTEXT , VLC_FALSE );
    add_module( "intf", "interface", NULL, NULL, INTF_TEXT,
                INTF_LONGTEXT, VLC_TRUE );
        change_short('I');
    add_string( "extraintf", NULL, NULL, EXTRAINTF_TEXT, 
                     EXTRAINTF_LONGTEXT, VLC_FALSE );
    add_integer( "verbose", 0, NULL, VERBOSE_TEXT, VERBOSE_LONGTEXT,
                 VLC_FALSE );
        change_short('v');
    add_bool( "quiet", 0, NULL, QUIET_TEXT, QUIET_LONGTEXT, VLC_TRUE );
        change_short('q');
    add_string( "language", "auto", NULL, LANGUAGE_TEXT, LANGUAGE_LONGTEXT,
                VLC_FALSE );
        change_string_list( ppsz_language, ppsz_language_text, 0 );
    add_bool( "color", 0, NULL, COLOR_TEXT, COLOR_LONGTEXT, VLC_TRUE );
    add_bool( "advanced", 0, NULL, ADVANCED_TEXT, 
                            ADVANCED_LONGTEXT, VLC_FALSE );
    add_directory( "search-path", NULL, NULL, INTF_PATH_TEXT, 
                            INTF_PATH_LONGTEXT, VLC_TRUE );
    add_directory( "plugin-path", NULL, NULL,
                PLUGIN_PATH_TEXT, PLUGIN_PATH_LONGTEXT, VLC_TRUE );

    /* Audio options */
    add_category_hint( N_("Audio"), AOUT_CAT_LONGTEXT , VLC_FALSE );
    add_module( "aout", "audio output", NULL, NULL, AOUT_TEXT, AOUT_LONGTEXT,
                VLC_TRUE );
        change_short('A');
    add_bool( "audio", 1, NULL, AUDIO_TEXT, AUDIO_LONGTEXT, VLC_FALSE );
    add_integer_with_range( "volume", AOUT_VOLUME_DEFAULT, AOUT_VOLUME_MIN,
                            AOUT_VOLUME_MAX, NULL, VOLUME_TEXT,
                            VOLUME_LONGTEXT, VLC_FALSE );
    add_integer_with_range( "saved-volume", AOUT_VOLUME_DEFAULT,
                            AOUT_VOLUME_MIN, AOUT_VOLUME_MAX, NULL,
                            VOLUME_SAVE_TEXT, VOLUME_SAVE_LONGTEXT, VLC_TRUE );
    add_integer( "aout-rate", -1, NULL, AOUT_RATE_TEXT, AOUT_RATE_LONGTEXT, VLC_TRUE );
#if !defined( SYS_DARWIN )
    add_bool( "hq-resampling", 1, NULL, AOUT_RESAMP_TEXT, AOUT_RESAMP_LONGTEXT, VLC_TRUE );
#endif
    add_bool( "spdif", 0, NULL, SPDIF_TEXT, SPDIF_LONGTEXT, VLC_FALSE );
#if 0
    add_bool( "headphone-opt", 0, NULL, HEADPHONE_TEXT, 
                        HEADPHONE_LONGTEXT, VLC_FALSE );
#endif
    add_integer( "audio-desync", 0, NULL, DESYNC_TEXT, DESYNC_LONGTEXT, VLC_TRUE );
    add_string("audio-filter",0,NULL,AUDIO_FILTER_TEXT,
                    AUDIO_FILTER_LONGTEXT,VLC_FALSE);
    
    /* Video options */
    add_category_hint( N_("Video"), VOUT_CAT_LONGTEXT , VLC_FALSE );
    add_module( "vout", "video output", NULL, NULL, VOUT_TEXT, VOUT_LONGTEXT,
                VLC_TRUE );
        change_short('V');
    add_bool( "video", 1, NULL, VIDEO_TEXT, VIDEO_LONGTEXT, VLC_TRUE );
    add_integer( "width", -1, NULL, WIDTH_TEXT, WIDTH_LONGTEXT, VLC_TRUE );
    add_integer( "height", -1, NULL, HEIGHT_TEXT, HEIGHT_LONGTEXT, VLC_TRUE );
    add_integer( "align", -1, NULL, ALIGN_TEXT, ALIGN_LONGTEXT, VLC_TRUE );
    add_float( "zoom", 1, NULL, ZOOM_TEXT, ZOOM_LONGTEXT, VLC_TRUE );
    add_bool( "grayscale", 0, NULL, GRAYSCALE_TEXT, GRAYSCALE_LONGTEXT, VLC_TRUE );
    add_bool( "fullscreen", 0, NULL, FULLSCREEN_TEXT, 
                        FULLSCREEN_LONGTEXT, VLC_FALSE );
#ifndef SYS_DARWIN
    add_bool( "overlay", 1, NULL, OVERLAY_TEXT, OVERLAY_LONGTEXT, VLC_TRUE );
#endif
    add_integer( "spumargin", -1, NULL, SPUMARGIN_TEXT, 
                        SPUMARGIN_LONGTEXT, VLC_TRUE );
    add_bool( "osd", 1, NULL, OSD_TEXT, OSD_LONGTEXT, VLC_FALSE );
    add_module( "filter", "video filter", NULL, NULL,
                FILTER_TEXT, FILTER_LONGTEXT, VLC_FALSE );
    add_string( "aspect-ratio", "", NULL,
                ASPECT_RATIO_TEXT, ASPECT_RATIO_LONGTEXT, VLC_TRUE );
#if 0
    add_string( "pixel-ratio", "1", NULL, PIXEL_RATIO_TEXT, PIXEL_RATIO_TEXT );
#endif

    /* Input options */
    add_category_hint( N_("Input"), INPUT_CAT_LONGTEXT , VLC_FALSE );
    add_integer( "server-port", 1234, NULL,
                 SERVER_PORT_TEXT, SERVER_PORT_LONGTEXT, VLC_FALSE );
    add_integer( "mtu", 1500, NULL, MTU_TEXT, MTU_LONGTEXT, VLC_TRUE );
    add_string( "iface-addr", "", NULL, IFACE_ADDR_TEXT, IFACE_ADDR_LONGTEXT, VLC_TRUE );

    add_integer( "program", 0, NULL,
                 INPUT_PROGRAM_TEXT, INPUT_PROGRAM_LONGTEXT, VLC_TRUE );
    add_integer( "audio-type", -1, NULL,
                 INPUT_AUDIO_TEXT, INPUT_AUDIO_LONGTEXT, VLC_TRUE );
    add_integer( "audio-channel", -1, NULL,
                 INPUT_CHAN_TEXT, INPUT_CHAN_LONGTEXT, VLC_TRUE );
    add_integer( "spu-channel", -1, NULL,
                 INPUT_SUBT_TEXT, INPUT_SUBT_LONGTEXT, VLC_TRUE );
    add_bool( "sub-autodetect-file", VLC_TRUE, NULL,
                 SUB_AUTO_TEXT, SUB_AUTO_LONGTEXT, VLC_FALSE );
    add_integer( "sub-autodetect-fuzzy", 3, NULL,
                 SUB_FUZZY_TEXT, SUB_FUZZY_LONGTEXT, VLC_TRUE );
    add_file( "sub-file", NULL, NULL,
                 SUB_FILE_TEXT, SUB_FILE_LONGTEXT, VLC_TRUE );


    add_file( "dvd", DVD_DEVICE, NULL, DVD_DEV_TEXT, DVD_DEV_LONGTEXT, VLC_FALSE );
    add_file( "vcd", VCD_DEVICE, NULL, VCD_DEV_TEXT, VCD_DEV_LONGTEXT, VLC_FALSE );

    add_bool( "ipv6", 0, NULL, IPV6_TEXT, IPV6_LONGTEXT, VLC_FALSE );
        change_short('6');
    add_bool( "ipv4", 0, NULL, IPV4_TEXT, IPV4_LONGTEXT, VLC_FALSE );
        change_short('4');

    /* Decoder options */
    add_category_hint( N_("Decoders"), CODEC_CAT_LONGTEXT , VLC_TRUE );
    add_module( "codec", "decoder", NULL, NULL, CODEC_TEXT, CODEC_LONGTEXT, VLC_TRUE );


    /* Stream output options */
    add_category_hint( N_("Stream output"), SOUT_CAT_LONGTEXT , VLC_TRUE );
    add_string( "sout", NULL, NULL, SOUT_TEXT, SOUT_LONGTEXT, VLC_TRUE );
    add_bool( "sout-display", VLC_FALSE, NULL, SOUT_DISPLAY_TEXT, 
                                SOUT_DISPLAY_LONGTEXT, VLC_TRUE );
    add_bool( "sout-keep", VLC_FALSE, NULL, SOUT_KEEP_TEXT, 
                                SOUT_KEEP_LONGTEXT, VLC_TRUE );

    add_bool( "sout-audio", 1, NULL, SOUT_AUDIO_TEXT, 
                                SOUT_AUDIO_LONGTEXT, VLC_TRUE );
    add_bool( "sout-video", 1, NULL, SOUT_VIDEO_TEXT, 
                                SOUT_VIDEO_LONGTEXT, VLC_TRUE );

    add_module( "packetizer", "packetizer", NULL, NULL,
                PACKETIZER_TEXT, PACKETIZER_LONGTEXT, VLC_TRUE );
    add_module( "mux", "sout mux", NULL, NULL, MUX_TEXT, 
                                MUX_LONGTEXT, VLC_TRUE );
    add_module( "access_output", "sout access", NULL, NULL,
                ACCESS_OUTPUT_TEXT, ACCESS_OUTPUT_LONGTEXT, VLC_TRUE );
    add_integer( "ttl", 1, NULL, TTL_TEXT, TTL_LONGTEXT, VLC_TRUE );


    /* CPU options */
    add_category_hint( N_("CPU"), CPU_CAT_LONGTEXT, VLC_TRUE );
#if defined( __i386__ )
    add_bool( "mmx", 1, NULL, MMX_TEXT, MMX_LONGTEXT, VLC_TRUE );
    add_bool( "3dn", 1, NULL, THREE_DN_TEXT, THREE_DN_LONGTEXT, VLC_TRUE );
    add_bool( "mmxext", 1, NULL, MMXEXT_TEXT, MMXEXT_LONGTEXT, VLC_TRUE );
    add_bool( "sse", 1, NULL, SSE_TEXT, SSE_LONGTEXT, VLC_TRUE );
#endif
#if defined( __powerpc__ ) || defined( SYS_DARWIN )
    add_bool( "altivec", 1, NULL, ALTIVEC_TEXT, ALTIVEC_LONGTEXT, VLC_TRUE );
#endif

    /* Playlist options */
    add_category_hint( N_("Playlist"), PLAYLIST_CAT_LONGTEXT , VLC_FALSE );
    add_bool( "random", 0, NULL, RANDOM_TEXT, RANDOM_LONGTEXT, VLC_FALSE );
        change_short('Z');
    add_bool( "loop", 0, NULL, LOOP_TEXT, LOOP_LONGTEXT, VLC_FALSE );
        change_short('L');
    add_bool( "repeat", 0, NULL, REPEAT_TEXT, REPEAT_LONGTEXT, VLC_TRUE );
        change_short('R');

    /* Misc options */
    add_category_hint( N_("Miscellaneous"), MISC_CAT_LONGTEXT, VLC_TRUE );
    add_module( "memcpy", "memcpy", NULL, NULL, MEMCPY_TEXT, MEMCPY_LONGTEXT, VLC_TRUE );
    add_module( "access", "access", NULL, NULL, ACCESS_TEXT, ACCESS_LONGTEXT, VLC_TRUE );
    add_module( "demux", "demux", NULL, NULL, DEMUX_TEXT, DEMUX_LONGTEXT, VLC_TRUE );

#if !defined(SYS_DARWIN) && defined(PTHREAD_COND_T_IN_PTHREAD_H)
    add_bool( "rt-priority", 0, NULL, RT_PRIORITY_TEXT, RT_PRIORITY_LONGTEXT, VLC_TRUE );
#endif

#if defined(WIN32)
    add_bool( "one-instance", 0, NULL, ONEINSTANCE_TEXT, ONEINSTANCE_LONGTEXT, VLC_TRUE );
    add_bool( "high-priority", 1, NULL, HPRIORITY_TEXT, HPRIORITY_LONGTEXT, VLC_TRUE );
    add_bool( "fast-mutex", 0, NULL, FAST_MUTEX_TEXT, FAST_MUTEX_LONGTEXT, VLC_TRUE );
    add_integer( "win9x-cv-method", 0, NULL, WIN9X_CV_TEXT, WIN9X_CV_LONGTEXT, VLC_TRUE );
#endif

    /* Hotkey options*/
    add_category_hint( N_("Hot keys"), HOTKEY_CAT_LONGTEXT , VLC_FALSE );
#if defined(SYS_DARWIN)
    add_key( "key-fullscreen", KEY_MODIFIER_COMMAND|'f', NULL, FULLSCREEN_KEY_TEXT, FULLSCREEN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-play-pause", KEY_MODIFIER_COMMAND|'p', NULL, PLAY_PAUSE_KEY_TEXT, PLAY_PAUSE_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-pause", 0, NULL, PAUSE_KEY_TEXT, PAUSE_KEY_LONGTEXT, VLC_TRUE );
    add_key( "key-play", 0, NULL, PLAY_KEY_TEXT, PLAY_KEY_LONGTEXT, VLC_TRUE );
    add_key( "key-faster", KEY_MODIFIER_COMMAND|'=', NULL, FASTER_KEY_TEXT, FASTER_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-slower", KEY_MODIFIER_COMMAND|'-', NULL, SLOWER_KEY_TEXT, SLOWER_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-next", KEY_MODIFIER_COMMAND|KEY_RIGHT, NULL, NEXT_KEY_TEXT, NEXT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-prev", KEY_MODIFIER_COMMAND|KEY_LEFT, NULL, PREV_KEY_TEXT, PREV_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-stop", KEY_MODIFIER_COMMAND|'.', NULL, STOP_KEY_TEXT, STOP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-10sec", KEY_MODIFIER_COMMAND|KEY_MODIFIER_ALT|KEY_LEFT, NULL, JB10SEC_KEY_TEXT, JB10SEC_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+10sec", KEY_MODIFIER_COMMAND|KEY_MODIFIER_ALT|KEY_RIGHT, NULL, JF10SEC_KEY_TEXT, JF10SEC_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-1min", KEY_MODIFIER_COMMAND|KEY_MODIFIER_SHIFT|KEY_LEFT, NULL, JB1MIN_KEY_TEXT, JB1MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+1min", KEY_MODIFIER_COMMAND|KEY_MODIFIER_SHIFT|KEY_RIGHT, NULL, JF1MIN_KEY_TEXT, JF1MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-5min", KEY_MODIFIER_COMMAND|KEY_MODIFIER_SHIFT|KEY_MODIFIER_ALT|KEY_LEFT, NULL, JB5MIN_KEY_TEXT, JB5MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+5min", KEY_MODIFIER_COMMAND|KEY_MODIFIER_SHIFT|KEY_MODIFIER_ALT|KEY_RIGHT, NULL, JF5MIN_KEY_TEXT, JF5MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-activate", KEY_ENTER, NULL, NAV_ACTIVATE_KEY_TEXT, NAV_ACTIVATE_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-up", KEY_UP, NULL, NAV_UP_KEY_TEXT, NAV_UP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-down", KEY_DOWN, NULL, NAV_DOWN_KEY_TEXT, NAV_DOWN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-left", KEY_LEFT, NULL, NAV_LEFT_KEY_TEXT, NAV_LEFT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-right", KEY_RIGHT, NULL, NAV_RIGHT_KEY_TEXT, NAV_RIGHT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-quit", KEY_MODIFIER_COMMAND|'q', NULL, QUIT_KEY_TEXT, QUIT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-vol-up", KEY_MODIFIER_COMMAND|KEY_UP, NULL, VOL_UP_KEY_TEXT, VOL_UP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-vol-down", KEY_MODIFIER_COMMAND|KEY_DOWN, NULL, VOL_DOWN_KEY_TEXT, VOL_DOWN_KEY_LONGTEXT, VLC_FALSE );
#else
    add_key( "key-fullscreen", 'f', NULL, FULLSCREEN_KEY_TEXT, FULLSCREEN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-play-pause", KEY_SPACE, NULL, PLAY_PAUSE_KEY_TEXT, PLAY_PAUSE_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-pause", 0, NULL, PAUSE_KEY_TEXT, PAUSE_KEY_LONGTEXT, VLC_TRUE );
    add_key( "key-play", 0, NULL, PLAY_KEY_TEXT, PLAY_KEY_LONGTEXT, VLC_TRUE );
    add_key( "key-faster", '+', NULL, FASTER_KEY_TEXT, FASTER_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-slower", '-', NULL, SLOWER_KEY_TEXT, SLOWER_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-next", 'n', NULL, NEXT_KEY_TEXT, NEXT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-prev", 'p', NULL, PREV_KEY_TEXT, PREV_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-stop", 's', NULL, STOP_KEY_TEXT, STOP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-10sec", KEY_MODIFIER_ALT|KEY_LEFT, NULL, JB10SEC_KEY_TEXT, JB10SEC_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+10sec", KEY_MODIFIER_ALT|KEY_RIGHT, NULL, JF10SEC_KEY_TEXT, JF10SEC_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-1min", KEY_MODIFIER_CTRL|KEY_LEFT, NULL, JB1MIN_KEY_TEXT, JB1MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+1min", KEY_MODIFIER_CTRL|KEY_RIGHT, NULL, JF1MIN_KEY_TEXT, JF1MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump-5min", KEY_MODIFIER_CTRL|KEY_MODIFIER_ALT|KEY_LEFT, NULL, JB5MIN_KEY_TEXT, JB5MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-jump+5min", KEY_MODIFIER_CTRL|KEY_MODIFIER_ALT|KEY_RIGHT, NULL, JF5MIN_KEY_TEXT, JF5MIN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-activate", KEY_ENTER, NULL, NAV_ACTIVATE_KEY_TEXT, NAV_ACTIVATE_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-up", KEY_UP, NULL, NAV_UP_KEY_TEXT, NAV_UP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-down", KEY_DOWN, NULL, NAV_DOWN_KEY_TEXT, NAV_DOWN_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-left", KEY_LEFT, NULL, NAV_LEFT_KEY_TEXT, NAV_LEFT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-nav-right", KEY_RIGHT, NULL, NAV_RIGHT_KEY_TEXT, NAV_RIGHT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-quit", KEY_MODIFIER_CTRL|'q', NULL, QUIT_KEY_TEXT, QUIT_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-vol-up", 'a', NULL, VOL_UP_KEY_TEXT, VOL_UP_KEY_LONGTEXT, VLC_FALSE );
    add_key( "key-vol-down", 'z', NULL, VOL_DOWN_KEY_TEXT, VOL_DOWN_KEY_LONGTEXT, VLC_FALSE );
#endif

    /* Usage (mainly useful for cmd line stuff) */
    add_usage_hint( PLAYLIST_USAGE );

    set_description( N_("main program") );
    set_capability( "main", 100 );
vlc_module_end();

static module_config_t p_help_config[] =
{
    { CONFIG_ITEM_BOOL, NULL, "help", 'h',
      N_("print help (can be combined with --advanced)") },
    { CONFIG_ITEM_BOOL, NULL, "longhelp", 'H',
      N_("print detailed help (can be combined with --advanced)") },
    { CONFIG_ITEM_BOOL, NULL, "list", 'l',
      N_("print a list of available modules") },
    { CONFIG_ITEM_STRING, NULL, "module", 'p',
      N_("print help on module (can be combined with --advanced)") },
    { CONFIG_ITEM_BOOL, NULL, "save-config", '\0',
      N_("save the current command line options in the config") },
    { CONFIG_ITEM_BOOL, NULL, "reset-config", '\0',
      N_("reset the current config to the default values") },
    { CONFIG_ITEM_STRING, NULL, "config", '\0',
      N_("use alternate config file") },
    { CONFIG_ITEM_BOOL, NULL, "version", '\0',
      N_("print version information") },
    { CONFIG_HINT_END, NULL, NULL, '\0', NULL }
};

/*****************************************************************************
 * End configuration.
 *****************************************************************************/

/*****************************************************************************
 * Initializer for the vlc_t structure storing the action / key associations
 *****************************************************************************/
static struct hotkey p_hotkeys[] =
{
    { "key-quit", ACTIONID_QUIT, 0 },
    { "key-play-pause", ACTIONID_PLAY_PAUSE, 0 },
    { "key-play", ACTIONID_PLAY, 0 },
    { "key-pause", ACTIONID_PAUSE, 0 },
    { "key-stop", ACTIONID_STOP, 0 },
    { "key-jump-10sec", ACTIONID_JUMP_BACKWARD_10SEC, 0 },
    { "key-jump+10sec", ACTIONID_JUMP_FORWARD_10SEC, 0 },
    { "key-jump-1min", ACTIONID_JUMP_BACKWARD_1MIN, 0 },
    { "key-jump+1min", ACTIONID_JUMP_FORWARD_1MIN, 0 },
    { "key-jump-5min", ACTIONID_JUMP_BACKWARD_5MIN, 0 },
    { "key-jump+5min", ACTIONID_JUMP_FORWARD_5MIN, 0 },
    { "key-prev", ACTIONID_PREV, 0 },
    { "key-next", ACTIONID_NEXT, 0 },
    { "key-faster", ACTIONID_FASTER, 0 },
    { "key-slower", ACTIONID_SLOWER, 0 },
    { "key-fullscreen", ACTIONID_FULLSCREEN, 0 },
    { "key-vol-up", ACTIONID_VOL_UP, 0 },
    { "key-vol-down", ACTIONID_VOL_DOWN, 0 },
    { "key-nav-activate", ACTIONID_NAV_ACTIVATE, 0 },
    { "key-nav-up", ACTIONID_NAV_UP, 0 },
    { "key-nav-down", ACTIONID_NAV_DOWN, 0 },
    { "key-nav-left", ACTIONID_NAV_LEFT, 0 },
    { "key-nav-right", ACTIONID_NAV_RIGHT, 0 },
    { NULL, 0, 0 }
};
