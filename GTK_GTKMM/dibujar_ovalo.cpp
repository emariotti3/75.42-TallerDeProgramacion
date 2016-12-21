#include <stdio.h>
#include <stdlib.h>
#include <gtkmm.h>

class Oval: public Gtk::DrawingArea{
    protected:
        virtual bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr){
            Gtk::Allocation alloc = get_allocation();
            int width = alloc.get_width();
            int height = alloc.get_height();

            int xc = width/2, yc = height/2;

            cr->save();
            
            cr->translate(xc, yc);
      			cr->scale(xc, yc);
            cr->arc(0, 0, 1.0, 0, 2*M_PI);
            cr->set_source_rgb(0.5,0.0,0.5);

            cr->fill();
            cr->stroke();

            cr->restore();
            return true;
        }
};

int main(int argc, char *argv[]){
    Gtk::Main kit(argc, argv);
    Oval oval;
    Gtk::Window window;
    window.set_title("OVAL");
    window.set_default_size(400,200);
    window.add(oval);
    window.show_all();
    Gtk::Main::run(window);
    return 0;
}
