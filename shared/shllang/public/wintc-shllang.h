#ifndef __WINTC_SHLLANG_H__
#define __WINTC_SHLLANG_H__

#include <glib.h>
#include <gtk/gtk.h>

//
// Punctuation related
//
typedef enum {
    WINTC_PUNC_NONE,
    WINTC_PUNC_MOREINPUT,
    WINTC_PUNC_ITEMIZATION
} WinTCPunctuationId;

//
// Control related
//
typedef enum {
    // Standard dialog buttons
    //
    WINTC_CTLTXT_OK,
    WINTC_CTLTXT_CANCEL,
    WINTC_CTLTXT_YES,
    WINTC_CTLTXT_NO,
    WINTC_CTLTXT_ABORT,
    WINTC_CTLTXT_RETRY,
    WINTC_CTLTXT_IGNORE,
    WINTC_CTLTXT_HELP,

    // Menus
    //
    WINTC_CTLTXT_FILEMENU,
    WINTC_CTLTXT_EDITMENU,
    WINTC_CTLTXT_VIEWMENU,
    WINTC_CTLTXT_INSERTMENU,
    WINTC_CTLTXT_FORMATMENU,
    WINTC_CTLTXT_TOOLSMENU,
    WINTC_CTLTXT_WINDOWMENU,
    WINTC_CTLTXT_HELPMENU,

    // File related
    // 
    WINTC_CTLTXT_NEW,
    WINTC_CTLTXT_BROWSE,
    WINTC_CTLTXT_OPEN,
    WINTC_CTLTXT_SAVE,
    WINTC_CTLTXT_SAVEAS,
    WINTC_CTLTXT_SAVEALL,
    WINTC_CTLTXT_CLOSE,
    WINTC_CTLTXT_CLOSEALL,
    WINTC_CTLTXT_PROPERTIES,

    WINTC_CTLTXT_PRINT,
    WINTC_CTLTXT_PRINTPREVIEW,
    WINTC_CTLTXT_PAGESETUP,

    WINTC_CTLTXT_EXIT,

    // Edit menus
    //
    WINTC_CTLTXT_UNDO,
    WINTC_CTLTXT_REDO,

    WINTC_CTLTXT_CUT,
    WINTC_CTLTXT_COPY,
    WINTC_CTLTXT_PASTE,
    WINTC_CTLTXT_DELETE,

    WINTC_CTLTXT_FIND,
    WINTC_CTLTXT_FINDNEXT,
    WINTC_CTLTXT_REPLACE,
    WINTC_CTLTXT_REPLACEALL,
    WINTC_CTLTXT_GOTO,

    WINTC_CTLTXT_SELECTALL,

    // View menus
    //
    WINTC_CTLTXT_ZOOM,
    WINTC_CTLTXT_ZOOMIN,
    WINTC_CTLTXT_ZOOMOUT,
    WINTC_CTLTXT_ZOOMFIT,
    WINTC_CTLTXT_ZOOMFULL,
    WINTC_CTLTXT_FULLSCREEN,
    WINTC_CTLTXT_STATUSBAR,

    // Format menus
    //
    WINTC_CTLTXT_FONT,
    WINTC_CTLTXT_FONTSTYLE,
    WINTC_CTLTXT_FONTSTYLE_BOLD,
    WINTC_CTLTXT_FONTSTYLE_ITALIC,
    WINTC_CTLTXT_FONTSTYLE_REGULAR,
    WINTC_CTLTXT_FONTSIZE,
    WINTC_CTLTXT_WORDWRAP,

    // Tools menus
    //
    WINTC_CTLTXT_OPTIONS,
    WINTC_CTLTXT_CUSTOMIZE,

    // Window menus
    //
    WINTC_CTLTXT_NEWWINDOW,
    WINTC_CTLTXT_NEWTAB,
    WINTC_CTLTXT_CLOSEWINDOW,
    WINTC_CTLTXT_CLOSETAB,

    // Help menus
    //
    WINTC_CTLTXT_HELPTOPICS,
    WINTC_CTLTXT_ABOUTPROGRAM
} WinTCControlTextId;

const gchar* wintc_get_control_text(
    WinTCControlTextId text_id,
    WinTCPunctuationId punc_id
);

//
// Place related
//
typedef enum {
    WINTC_PLACE_APPDATA,
    WINTC_PLACE_DESKTOP,
    WINTC_PLACE_DOWNLOADS,
    WINTC_PLACE_FAVORITES,
    WINTC_PLACE_DOCUMENTS,
    WINTC_PLACE_MUSIC,
    WINTC_PLACE_PICTURES,
    WINTC_PLACE_RECENTS,
    WINTC_PLACE_RECYCLEBIN,
    WINTC_PLACE_VIDEO,
    WINTC_PLACE_ADMINTOOLS,
    WINTC_PLACE_DRIVES,
    WINTC_PLACE_NETHOOD,
    WINTC_PLACE_CONTROLPANEL,
    WINTC_PLACE_CONNECTIONS,
    WINTC_PLACE_PRINTERS
} WinTCShellPlace;

const gchar* wintc_get_place_name(
    WinTCShellPlace place
);

//
// UI related
//
wintc_preprocess_builder_widget_text(
    GtkBuilder* builder
);

#endif
