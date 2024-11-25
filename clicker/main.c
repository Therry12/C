#include "glib-object.h"
#include "gtk/gtk.h"
#include "gtk/gtkshortcut.h"

#include <stdio.h>

static int increment() {
    static int i = 0;
    g_print("Clicked %d times: \n", i++);
    return i;
}

static void clicks_to_str(GtkLabel* label) {
    char str[100];
    sprintf(str, "Clicked: %d", increment());
    gtk_label_set_text(label, str);
}

static void activate(GtkApplication* app) {
    GtkWidget* window;
    GtkWidget* click_button;
    GtkWidget* clicked_info_label;
    GtkWidget* grid;
    char str[100] = {};

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Clicker");

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

    clicked_info_label = gtk_label_new("Clicked: 0");

    click_button = gtk_button_new_with_label("+");
    g_signal_connect_swapped(click_button, "clicked", G_CALLBACK(clicks_to_str), clicked_info_label);

    gtk_grid_attach(GTK_GRID(grid), click_button, 0, 0, 1, 5);
    gtk_grid_attach(GTK_GRID(grid), clicked_info_label, 0, 5, 1, 5);

    gtk_window_present(GTK_WINDOW(window));
}

int main() {
    GtkApplication* clicker;
    int status;

    clicker = gtk_application_new("org.gtk.clicker", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(clicker, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(clicker), 0, NULL);
    g_object_unref(clicker);

    return status;
}
