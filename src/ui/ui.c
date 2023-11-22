// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
lv_obj_t *ui_Screen2;
void ui_event_Slider3( lv_event_t * e);
lv_obj_t *ui_Slider3;
void ui_event_Slider4( lv_event_t * e);
lv_obj_t *ui_Slider4;
lv_obj_t *ui_DutyLabel1;
lv_obj_t *ui_FreqLabel1;
lv_obj_t *ui_DutyLabel3;
lv_obj_t *ui_FreqLabel3;
void ui_event_SetFreqBTN2_Button( lv_event_t * e);
lv_obj_t *ui_SetFreqBTN2;
lv_obj_t *ui_Label1;
void ui_event_SetDutyBTN2_Button( lv_event_t * e);
lv_obj_t *ui_SetDutyBTN2;
lv_obj_t *ui_Label2;


// SCREEN: ui_ScreenSetFreq
void ui_ScreenSetFreq_screen_init(void);
lv_obj_t *ui_ScreenSetFreq;
void ui_event_Panel3( lv_event_t * e);
lv_obj_t *ui_Panel3;
lv_obj_t *ui_ApplyLabel;
lv_obj_t *ui_Panel4;
lv_obj_t *ui_TextArea1;
lv_obj_t *ui_Panel5;
lv_obj_t *ui_Keyboard2;


// SCREEN: ui_ScreenSetDuty
void ui_ScreenSetDuty_screen_init(void);
lv_obj_t *ui_ScreenSetDuty;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_TextArea2;
lv_obj_t *ui_Panel6;
lv_obj_t *ui_Keyboard1;
lv_obj_t *ui_Panel1;
void ui_event_Button1( lv_event_t * e);
lv_obj_t *ui_Button1;
lv_obj_t *ui_Label3;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Slider3( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_RELEASED) {
      _ui_slider_set_text_value( ui_FreqLabel3, target, "", "");
      freqgo2( e );
}
}
void ui_event_Slider4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_RELEASED) {
      _ui_slider_set_text_value( ui_DutyLabel3, target, "", "");
      dutygo2( e );
}
}
void ui_event_SetFreqBTN2_Button( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_RELEASED) {
      _ui_screen_change( &ui_ScreenSetFreq, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScreenSetFreq_screen_init);
}
}
void ui_event_SetDutyBTN2_Button( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenSetDuty, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ScreenSetDuty_screen_init);
}
}
void ui_event_Panel3( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      applyfreq( e );
}
if ( event_code == LV_EVENT_RELEASED) {
      _ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen2_screen_init);
}
}
void ui_event_Button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      myduty( e );
}
if ( event_code == LV_EVENT_RELEASED) {
      _ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen2_screen_init);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen2_screen_init();
ui_ScreenSetFreq_screen_init();
ui_ScreenSetDuty_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_Screen2);
}
