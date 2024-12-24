
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>

GtkEntry *txt_a;
GtkEntry *txt_b;
GtkLabel *lab_res;

float a, b;
char tr[20];

void get_ab()
{
	const gchar *ta = gtk_entry_get_text(txt_a);
	const gchar *tb = gtk_entry_get_text(txt_b);

	a = atof(ta);
	b = atof(tb);
}

void set_r(float r)
{
	sprintf(tr, "%.5f", r);
	gtk_label_set_text(lab_res, tr);
}

void on_wnd_destroy(GtkWidget* widget)
{
	gtk_main_quit();
}

void on_sin_click(GtkButton* button)
{
	get_ab();
	set_r(sinf(a));
}

void on_cos_click(GtkButton* button)
{
	get_ab();
	set_r(cosf(a));
}

void on_btn_add_click(GtkButton* button)
{
	get_ab();
	set_r(a + b);
}

void on_btn_sub_click(GtkButton* button)
{
	get_ab();
	set_r(a - b);
}

void on_btn_mul_click(GtkButton* button)
{
	get_ab();
	set_r(a * b);
}

void on_btn_div_click(GtkButton* button)
{
	get_ab();
	set_r(a / b);
}

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "ui.glade", NULL);

	txt_a = (GtkEntry *) gtk_builder_get_object(builder, "txt_a");
	txt_b = (GtkEntry *) gtk_builder_get_object(builder, "txt_b");
	lab_res = (GtkLabel *) gtk_builder_get_object(builder, "lab_res");

	GtkWidget *wnd = (GtkWidget *) gtk_builder_get_object(builder, "wnd");

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show_all(wnd);

	gtk_main();

	return 0;
}
