#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#define MY_UUID { 0xD4, 0xED, 0x05, 0xFF, 0x75, 0x8B, 0x46, 0x6F, 0x80, 0xBF, 0x55, 0xFA, 0xD9, 0xCB, 0xAA, 0x3C }
PBL_APP_INFO(MY_UUID,
             "WARNING BELL",
             "SAH",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;

TextLayer top_layer;
TextLayer center_layer;
TextLayer bottom_layer;
TextLayer centertwo_layer;

const VibePattern custom_pattern = {
  .durations = (uint32_t []) {75, 500},
  .num_segments = 2
};

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "WarningBell");
  window_stack_push(&window, true /* Animated */);
  window_set_background_color(&window, GColorBlack);
	
  resource_init_current_app(&APP_RESOURCES);
	
  text_layer_init(&top_layer, GRect(0, 10, 144, 37));
  text_layer_set_text(&top_layer, "Its a");
  text_layer_set_text_color(&top_layer, GColorWhite);
  text_layer_set_background_color(&top_layer, GColorClear);
  text_layer_set_font(&top_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_text_alignment(&top_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &top_layer.layer);

  text_layer_init(&center_layer, GRect(0, 47, 144 /* width */, 37 /* height */));
  text_layer_set_text(&center_layer, "BIG");
  text_layer_set_text_color(&center_layer, GColorWhite);
  text_layer_set_background_color(&center_layer, GColorClear);
  text_layer_set_font(&center_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(&center_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &center_layer.layer);
	
  text_layer_init(&centertwo_layer, GRect(0, 84, 144 /* width */, 37 /* height */));
  text_layer_set_text(&centertwo_layer, "Beautiful");
  text_layer_set_text_color(&centertwo_layer, GColorWhite);
  text_layer_set_background_color(&centertwo_layer, GColorClear);
  text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(&centertwo_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &centertwo_layer.layer);

  text_layer_init(&bottom_layer, GRect(0, 121, 144 /* width */, 37 /* height */));
  text_layer_set_text(&bottom_layer, "Tomarrow!");
  text_layer_set_text_color(&bottom_layer, GColorWhite);
  text_layer_set_background_color(&bottom_layer, GColorClear);
  text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(&bottom_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &bottom_layer.layer);
	
}

void handle_minute_tick(AppContextRef ctx, PebbleTickEvent *t) {
  (void)ctx;
	
  /* This is the object where we will get our time, it is the equivalent of the t variable in our JS version */
  PblTm q;

  /* Get the current time from our time object */
  get_time(&q);
	
  int minute = q.tm_min;
  int hour = q.tm_hour;
  int weekDay = q.tm_wday;
	
  /* FYI:
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  */
		
  int offset = 2; // School's Clocks Run 2 Minutes Fast...
	
  int minutesPastMidnight = (((hour*60) + minute) + offset);
  int remaining = 999;	

	if(weekDay <= 2 || (weekDay > 3 && weekDay <= 5)){
		
		if(minutesPastMidnight <= 450){
			text_layer_set_text(&centertwo_layer, "Rise and Shine!");
			remaining = 450 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 450) && (minutesPastMidnight <= 480)){
			text_layer_set_text(&centertwo_layer, "Get Ready!");
			remaining = 480 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 480) && (minutesPastMidnight <= 526)){
			text_layer_set_text(&centertwo_layer, "Intro To Tech");
			remaining = 526 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 526) && (minutesPastMidnight <= 530)){
			text_layer_set_text(&centertwo_layer, "1st --> 2nd");
			remaining = 530 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 530) && (minutesPastMidnight <= 576)){
			text_layer_set_text(&centertwo_layer, "Electronics");
			remaining = 576 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 576) && (minutesPastMidnight <= 580)){
			text_layer_set_text(&centertwo_layer, "2nd --> 3rd");
			remaining = 580 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 580) && (minutesPastMidnight <= 628)){
			text_layer_set_text(&centertwo_layer, "Intro To Tech");
			remaining = 628 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 628) && (minutesPastMidnight <= 632)){
			text_layer_set_text(&centertwo_layer, "3rd --> 4th");
			remaining = 632 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 632) && (minutesPastMidnight <= 678)){
			text_layer_set_text(&centertwo_layer, "4th Prep.");
			remaining = 678 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 678) && (minutesPastMidnight <= 710)){
			text_layer_set_text(&centertwo_layer, "Lunch");
			remaining = 710 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 710) && (minutesPastMidnight <= 758)){
			text_layer_set_text(&centertwo_layer, "5th Prep.");
			remaining = 758 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 758) && (minutesPastMidnight <= 762)){
			text_layer_set_text(&centertwo_layer, "5th --> 6th");
			remaining = 762 - minutesPastMidnight;
		}
		else if((minutesPastMidnight > 762) && (minutesPastMidnight <= 808)){
			text_layer_set_text(&centertwo_layer, "Engineering");
			remaining = 808 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 808) && (minutesPastMidnight <= 812)){
			text_layer_set_text(&centertwo_layer, "6th --> 7th");
			remaining = 812 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 812) && (minutesPastMidnight <= 858)){
			text_layer_set_text(&centertwo_layer, "Architecture");
			remaining = 858 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 858) && (minutesPastMidnight <= 862)){
			text_layer_set_text(&centertwo_layer, "7th --> 8th");
			remaining = 862 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 862) && (minutesPastMidnight <= 909)){
			text_layer_set_text(&centertwo_layer, "Manufacturing");
			remaining = 909 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 909) && (minutesPastMidnight <= 930)){
			text_layer_set_text(&centertwo_layer, "Wrap it Up!");
			remaining = 930 - minutesPastMidnight;
		}	
		else{
			text_layer_set_text(&centertwo_layer, "Good Night!");
			remaining = 1890 - minutesPastMidnight;
		}	
	
		static char debugtxt[20];
		PblTm tmp;
		tmp.tm_min = remaining + 1;
		string_format_time(debugtxt, sizeof(debugtxt), "< %M Min.", &tmp);
		
	    text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
		text_layer_set_font(&center_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  		text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
		
		if(remaining == 5){
			vibes_enqueue_custom_pattern(custom_pattern);
		}
		if(remaining <= 5){
			window_set_background_color(&window, GColorWhite);
			text_layer_set_text_color(&top_layer, GColorBlack);
			text_layer_set_text_color(&center_layer, GColorBlack);
			text_layer_set_text_color(&centertwo_layer, GColorBlack);
			text_layer_set_text_color(&bottom_layer, GColorBlack);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
			text_layer_set_text(&bottom_layer, debugtxt);
		}
		else if(remaining >= 59){
			window_set_background_color(&window, GColorBlack);
			text_layer_set_text_color(&top_layer, GColorWhite);
			text_layer_set_text_color(&center_layer, GColorWhite);
			text_layer_set_text_color(&centertwo_layer, GColorWhite);
			text_layer_set_text_color(&bottom_layer, GColorWhite);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
			text_layer_set_text(&bottom_layer, "> 1 Hour");
		}
		else{
			window_set_background_color(&window, GColorBlack);
			text_layer_set_text_color(&top_layer, GColorWhite);
			text_layer_set_text_color(&center_layer, GColorWhite);
			text_layer_set_text_color(&centertwo_layer, GColorWhite);
			text_layer_set_text_color(&bottom_layer, GColorWhite);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
			text_layer_set_text(&bottom_layer, debugtxt);
		}

	  // Need to be static because they're used by the system later.
	  static char time_text[] = "00:00";
	  static char date_text[] = "Xxxxxxxxx 00";
	
	  char *time_format;
	
	
	  // TODO: Only update the date when it's changed.
	  string_format_time(date_text, sizeof(date_text), "%a, %b %e", t->tick_time);
	  text_layer_set_text(&center_layer, date_text);
	
	
	  if (clock_is_24h_style()) {
		time_format = "%R";
	  } else {
		time_format = "%I:%M";
	  }
	
	  string_format_time(time_text, sizeof(time_text), time_format, t->tick_time);
	
	  // Kludge to handle lack of non-padded hour format string
	  // for twelve hour clock.
	  if (!clock_is_24h_style() && (time_text[0] == '0')) {
		memmove(time_text, &time_text[1], sizeof(time_text) - 1);
	  }
	
	  text_layer_set_text(&top_layer, time_text);
		
	}
	else if(weekDay == 3){
		if(minutesPastMidnight <= 450){
			text_layer_set_text(&centertwo_layer, "Rise and Shine!");
			remaining = 450 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 450) && (minutesPastMidnight <= 480)){
			text_layer_set_text(&centertwo_layer, "Get Ready!");
			remaining = 480 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 480) && (minutesPastMidnight <= 526)){
			text_layer_set_text(&centertwo_layer, "Intro To Tech");
			remaining = 526 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 526) && (minutesPastMidnight <= 530)){
			text_layer_set_text(&centertwo_layer, "1st --> 2nd");
			remaining = 530 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 530) && (minutesPastMidnight <= 576)){
			text_layer_set_text(&centertwo_layer, "Electronics");
			remaining = 576 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 576) && (minutesPastMidnight <= 580)){
			text_layer_set_text(&centertwo_layer, "2nd --> 3rd");
			remaining = 580 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 580) && (minutesPastMidnight <= 628)){
			text_layer_set_text(&centertwo_layer, "Intro To Tech");
			remaining = 628 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 628) && (minutesPastMidnight <= 632)){
			text_layer_set_text(&centertwo_layer, "3rd --> READ");
			remaining = 632 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 628) && (minutesPastMidnight <= 632)){
			text_layer_set_text(&centertwo_layer, "Reading Block");
			remaining = 632 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 628) && (minutesPastMidnight <= 632)){
			text_layer_set_text(&centertwo_layer, "READ --> 4th");
			remaining = 632 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 632) && (minutesPastMidnight <= 678)){
			text_layer_set_text(&centertwo_layer, "4th Prep.");
			remaining = 678 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 678) && (minutesPastMidnight <= 710)){
			text_layer_set_text(&centertwo_layer, "Lunch");
			remaining = 710 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 710) && (minutesPastMidnight <= 758)){
			text_layer_set_text(&centertwo_layer, "5th Prep.");
			remaining = 758 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 758) && (minutesPastMidnight <= 762)){
			text_layer_set_text(&centertwo_layer, "5th --> 6th");
			remaining = 762 - minutesPastMidnight;
		}
		else if((minutesPastMidnight > 762) && (minutesPastMidnight <= 808)){
			text_layer_set_text(&centertwo_layer, "Engineering");
			remaining = 808 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 808) && (minutesPastMidnight <= 812)){
			text_layer_set_text(&centertwo_layer, "6th --> 7th");
			remaining = 812 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 812) && (minutesPastMidnight <= 858)){
			text_layer_set_text(&centertwo_layer, "Architecture");
			remaining = 858 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 858) && (minutesPastMidnight <= 862)){
			text_layer_set_text(&centertwo_layer, "7th --> 8th");
			remaining = 862 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 862) && (minutesPastMidnight <= 909)){
			text_layer_set_text(&centertwo_layer, "Manufacturing");
			remaining = 909 - minutesPastMidnight;
		}	
		else if((minutesPastMidnight > 909) && (minutesPastMidnight <= 930)){
			text_layer_set_text(&centertwo_layer, "Wrap it Up!");
			remaining = 930 - minutesPastMidnight;
		}	
		else{
			text_layer_set_text(&centertwo_layer, "Good Night!");
			remaining = 1890 - minutesPastMidnight;
		}	
	
		static char debugtxt[20];
		PblTm tmp;
		tmp.tm_min = remaining + 1;
		string_format_time(debugtxt, sizeof(debugtxt), "< %M Min.", &tmp);
		
	    text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
		text_layer_set_font(&center_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  		text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
		
		if(remaining == 5){
			vibes_enqueue_custom_pattern(custom_pattern);
		}
		if(remaining <= 5){
			window_set_background_color(&window, GColorWhite);
			text_layer_set_text_color(&top_layer, GColorBlack);
			text_layer_set_text_color(&center_layer, GColorBlack);
			text_layer_set_text_color(&centertwo_layer, GColorBlack);
			text_layer_set_text_color(&bottom_layer, GColorBlack);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
			text_layer_set_text(&bottom_layer, debugtxt);
		}
		else if(remaining >= 59){
			window_set_background_color(&window, GColorBlack);
			text_layer_set_text_color(&top_layer, GColorWhite);
			text_layer_set_text_color(&center_layer, GColorWhite);
			text_layer_set_text_color(&centertwo_layer, GColorWhite);
			text_layer_set_text_color(&bottom_layer, GColorWhite);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
			text_layer_set_text(&bottom_layer, "> 1 Hour");
		}
		else{
			window_set_background_color(&window, GColorBlack);
			text_layer_set_text_color(&top_layer, GColorWhite);
			text_layer_set_text_color(&center_layer, GColorWhite);
			text_layer_set_text_color(&centertwo_layer, GColorWhite);
			text_layer_set_text_color(&bottom_layer, GColorWhite);
			text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
			text_layer_set_text(&bottom_layer, debugtxt);
		}
	  
	  // Need to be static because they're used by the system later.
	  static char time_text[] = "00:00";
	  static char date_text[] = "Xxxxxxxxx 00";
	
	  char *time_format;
	
	
	  // TODO: Only update the date when it's changed.
	  string_format_time(date_text, sizeof(date_text), "%a, %b %e", t->tick_time);
	  text_layer_set_text(&center_layer, date_text);
	
	
	  if (clock_is_24h_style()) {
		time_format = "%R";
	  } else {
		time_format = "%I:%M";
	  }
	
	  string_format_time(time_text, sizeof(time_text), time_format, t->tick_time);
	
	  // Kludge to handle lack of non-padded hour format string
	  // for twelve hour clock.
	  if (!clock_is_24h_style() && (time_text[0] == '0')) {
		memmove(time_text, &time_text[1], sizeof(time_text) - 1);
	  }
	
	  text_layer_set_text(&top_layer, time_text);
	}
	else{	
		window_set_background_color(&window, GColorBlack);
		text_layer_set_text_color(&top_layer, GColorWhite);
		text_layer_set_text_color(&center_layer, GColorWhite);
		text_layer_set_text_color(&centertwo_layer, GColorWhite);
		text_layer_set_text_color(&bottom_layer, GColorWhite);
		text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
		text_layer_set_font(&center_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  		text_layer_set_font(&centertwo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
		text_layer_set_font(&bottom_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
		text_layer_set_text(&top_layer, "Just a spark");
		text_layer_set_text(&center_layer, "of inspiration");
		text_layer_set_text(&centertwo_layer, "is at the heart");
		text_layer_set_text(&bottom_layer, "of all creation!");
	}
	
	
	/*switch (weekDay)
	{
		case 0: text_layer_set_text(&center_layer, "Zero"); break;
		case 1: text_layer_set_text(&center_layer, "One"); break;
		case 2: text_layer_set_text(&center_layer, "Two"); break;
		case 3: text_layer_set_text(&center_layer, "Three"); break;
		case 4: text_layer_set_text(&center_layer, "Four"); break;
		case 5: text_layer_set_text(&center_layer, "Five"); break;
		case 6: text_layer_set_text(&center_layer, "Six"); break;
		case 7: text_layer_set_text(&center_layer, "Seven"); break;
		case 8: text_layer_set_text(&center_layer, "Eight"); break;
		case 9: text_layer_set_text(&center_layer, "Nine"); break;
	}*/

}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,

    .tick_info = {
      .tick_handler = &handle_minute_tick,
      .tick_units = MINUTE_UNIT
    }

  };
  app_event_loop(params, &handlers);
}