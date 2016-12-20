#include <stdio.h>
#include <stdlib.h>
#include <gtkmm.h>

class Cross: public Gtk::DrawingArea{
    public:
        bool on_draw(const Cairo::RefPtr<Cairo::Context> &ctx);
};

bool Cross::on_draw(const Cairo::RefPtr<Cairo::Context> &ctx){
    Glib::RefPtr<Gdk::Window> window = get_window();
    if (window){
        Gtk::Allocation alloc = get_allocation();
        int width = alloc.get_width();
        int height = alloc.get_height();

        ctx->save();

        ctx->set_line_width(20.0);
        ctx->set_source_rgb(0.0,0.0,1.0);

        ctx->move_to(width/2, height);
        ctx->line_to(width/2, 0);

        ctx->move_to(0, height/2);
        ctx->line_to(width, height/2);

        ctx->stroke();
        ctx->restore();
    }
}

class Window: public Gtk::Window{
    private:
        Cross cross;
    public:
        Window();
};

Window::Window(){
    this->set_default_size(200,200);
    this->set_title("GTK CROSS");
    this->add(this->cross);
    this->show_all();
}

int main(int argc, char *argv[]){
    Gtk::Main kit(argc, argv);
    Window window;
    Gtk::Main::run(window);
    return 0;
}
