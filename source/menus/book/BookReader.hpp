#ifndef EBOOK_READER_BOOK_READER_HPP
#define EBOOK_READER_BOOK_READER_HPP

#include <mupdf/pdf.h>
#include <string>
#include "PageLayout.hpp"
#include <switch.h>
struct SDL_Texture;

typedef enum {
    BookPageLayoutPortrait,
    BookPageLayoutLandscape
} BookPageLayout;

class BookReader {
    public:
        BookReader(const char *path, int *result);
        ~BookReader();

        bool permStatusBar = false;

        void previous_page(int n);
        void next_page(int n);
        void zoom_in();
        void zoom_out();
        void move_page_up();
        void move_page_down();
        void move_page_left();
        void move_page_right();
        void reset_page();
        void switch_page_layout();
        void draw(bool drawHelp);
    
        BookPageLayout currentPageLayout() {
            return _currentPageLayout;
        }
    
    private:
        void show_status_bar();
        void switch_current_page_layout(BookPageLayout bookPageLayout, int current_page);
    
        fz_document *doc = NULL;
        int status_bar_visible_counter = 0;
    
        BookPageLayout _currentPageLayout = BookPageLayoutPortrait;
        PageLayout *layout = NULL;
    
        std::string book_name;
};

#endif
