#include <glib.h>
#include <glib/gi18n.h>
#include <locale.h>
#include <wintc-shllang.h>

#include "application.h"
#include "meta.h"

int main(
    int   argc,
    char* argv[]
)
{
    // Set up locales
    //
    setlocale(LC_ALL, "");
    bindtextdomain(PKG_NAME, WINTC_LOCALE_DIR);
    textdomain(PKG_NAME);

    // Launch application
    //
    WinTCMinesApplication* app = wintc_mines_application_new();
    int status;

    g_set_application_name("Minesweeper");

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}
