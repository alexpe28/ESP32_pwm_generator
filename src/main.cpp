#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <driver/mcpwm.h>
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"
#include <ui/ui.h>

// #define PWM_gpio21 21
// int Freq_gpio21 = 8000; // частота канала
// float Duty21 = 50;      // переменная для записи скважности ШИМ

#define PWM_gpio22 22
int Freq_gpio22 = 32000;
float Duty22 = 50;

char chfreq[5] = "0";
const char *constfreq = chfreq;

char chduty[5] = "0";
const char *constduty = chduty;

void pwminit2()
{
    mcpwm_config_t pwm_config2;
    pwm_config2.frequency = Freq_gpio22; // Частота
    pwm_config2.cmpr_a = Duty22;          // Заполнение MCPWM2A
    pwm_config2.cmpr_b = Duty22;     // Заполнение MCPWM2B
    pwm_config2.duty_mode = MCPWM_DUTY_MODE_0;
    pwm_config2.counter_mode = MCPWM_UP_COUNTER;
    mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_2, &pwm_config2); // Настройка MCPWM2
}

void myduty(lv_event_t *e)
{
    String sduty = lv_textarea_get_text(ui_TextArea2);
    Serial.println("sduty = " + sduty);
    Duty22 = sduty.toInt();
    Serial.println("Duty_gpio22 = " + String(Duty22));
    pwminit2();
    strcpy(chduty, sduty.c_str());
    lv_label_set_text(ui_DutyLabel3, constduty);
}

void applyfreq(lv_event_t *e)
{
    String sfreq = lv_textarea_get_text(ui_TextArea1);
    Serial.println("sfreq = " + sfreq);
    int tempfreq = sfreq.toInt()/8;
    Freq_gpio22 = tempfreq*8;
    Serial.println("Freq_gpio22 = " + String(Freq_gpio22));
    pwminit2();
    strcpy(chfreq, String(Freq_gpio22).c_str());
    lv_label_set_text(ui_FreqLabel3, constfreq);
}

void freqgo2(lv_event_t *e)
{
    int tempfreq = lv_slider_get_value(ui_Slider3)/8;
    Freq_gpio22 = tempfreq*8;
    Serial.println("Freq_gpio22 = " + String(Freq_gpio22));
    pwminit2();
    strcpy(chfreq, String(Freq_gpio22).c_str());
    lv_label_set_text(ui_FreqLabel3, constfreq);
}

void dutygo2(lv_event_t *e)
{
    Duty22 = lv_slider_get_value(ui_Slider4);
    Serial.println("Duty22 = " + String(Duty22));
    pwminit2();   
    strcpy(chduty, String(Duty22).c_str());
    lv_label_set_text(ui_DutyLabel3, constduty);
}

void setup()
{
    Serial.begin(115200);
    smartdisplay_init();
    ui_init();


    // mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1A, PWM_gpio21);
    mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM2A, PWM_gpio22);
    // pwminit1();
    pwminit2();
}

void loop()
{
    lv_timer_handler();
}