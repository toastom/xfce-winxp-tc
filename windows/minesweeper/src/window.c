#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include <wintc-comgtk.h>
#include <wintc-shllang.h>
#include <stdbool.h>

#include "application.h"
#include "window.h"

#define DEFAULT_BLOCKS 9
#define BLOCK_SIZE 	   16
#define WINDOW_WIDTH  BLOCK_SIZE * DEFAULT_BLOCKS
#define WINDOW_HEIGHT BLOCK_SIZE * DEFAULT_BLOCKS

//
// FORWARD DECLARATIONS
//
static void action_notimpl(
    GSimpleAction* action,
    GVariant*      parameter,
    gpointer       user_data
);

gboolean on_click(
	GtkWidget* button,
	GdkEvent* event,
	gpointer user_data
);


//
// STATIC DATA
//
static GActionEntry s_window_actions[] = {
    {
        .name           = "notimpl",
        .activate       = action_notimpl,
        .parameter_type = NULL,
        .state          = NULL,
        .change_state   = NULL
    }
	/*
	{
        .name           = "activate",
        .activate       = action_click,
        .parameter_type = NULL,
        .state          = NULL,
        .change_state   = NULL
    }
	*/
};

//
// GTK OOP CLASS/INSTANCE DEFINITIONS
//
struct _WinTCMinesWindowClass
{
    GtkApplicationWindowClass __parent__;
};

struct _WinTCMinesWindow
{
    GtkApplicationWindow __parent__;
};

//
// GTK TYPE DEFINITION & CTORS
//
G_DEFINE_TYPE(
    WinTCMinesWindow,
    wintc_mines_window,
    GTK_TYPE_APPLICATION_WINDOW
)

static void wintc_mines_window_class_init(
    WINTC_UNUSED(WinTCMinesWindowClass* klass)
) {}

static void wintc_mines_window_init(
    WinTCMinesWindow* self
)
{
    // Define GActions
    //
    g_action_map_add_action_entries(
        G_ACTION_MAP(self),
        s_window_actions,
        G_N_ELEMENTS(s_window_actions),
        self
    );

    // FIXME: Should restore window size if possible
    //
    gtk_window_set_default_size(
        GTK_WINDOW(self),
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );
	
    // Initialize UI
    //
	
	GtkBuilder* builder;
    GtkWidget*  main_box;
	
    builder =
        gtk_builder_new_from_resource(
            "/uk/oddmatics/wintc/minesweeper/minesweeper.ui"
        );

    wintc_preprocess_builder_widget_text(builder);
    main_box = GTK_WIDGET(gtk_builder_get_object(builder, "main-box"));
    gtk_container_add(GTK_CONTAINER(self), main_box);
	
	GtkGrid* grid;// = (GtkGrid*)gtk_grid_new();
	grid = GTK_GRID(gtk_builder_get_object(builder, "grid"));
	//gtk_grid_attach(grid, NULL, 0, 0, 1, 1); // error
	
	for(int i = 0; i < DEFAULT_BLOCKS; i++) {
		for(int j = 0; j < DEFAULT_BLOCKS; j++) {
			GtkWidget* button = gtk_button_new_with_label("1");
			gtk_widget_set_visible(button, true);
			gtk_grid_attach(grid, button, j, i, 1, 1);
			
			
			g_signal_connect(button, "button_press_event", G_CALLBACK(on_click), NULL);
		}
	}
	
}

//
// PUBLIC FUNCTIONS
//
GtkWidget* wintc_mines_window_new(
    WinTCMinesApplication* app
)
{
    return GTK_WIDGET(
        g_object_new(
            TYPE_WINTC_MINES_WINDOW,
            "application", GTK_APPLICATION(app),
            "title",       _("Minesweeper"),
            NULL
        )
    );
}

//
// CALLBACKS
//
static void action_notimpl(
    WINTC_UNUSED(GSimpleAction* action),
    WINTC_UNUSED(GVariant*      parameter),
    WINTC_UNUSED(gpointer       user_data)
)
{
    GError* error = NULL;

    g_set_error(
        &error,
        WINTC_GENERAL_ERROR,
        WINTC_GENERAL_ERROR_NOTIMPL,
        "%s",
        "Action not implemented."
    );

    wintc_nice_error_and_clear(&error);
}

gboolean on_click(WINTC_UNUSED(GtkWidget* button), GdkEvent* event, WINTC_UNUSED(gpointer user_data)){
	guint mouse_button;
	gdk_event_get_button(event, &mouse_button);
	g_print("mouse btn: %d\n", mouse_button);
	// NOTE: remember GDK_BUTTON_SECONDARY, also assume there's a PRIMARY for left click too
	
	return TRUE;
}





