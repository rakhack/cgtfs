#ifndef CGTFS_TESTS__ALL_C
#define CGTFS_TESTS__ALL_C

#include "test-haversine.c"
#include "test-parsing_functions.c"
#include "test-read_functions.c"
#include "test-reading.c"
#include "test-reading_utils.c"

int main(int argc, char **argv) {
    test_haversine_correct();

    test_pf_exception_type();
    test_pf_service_availability();
    test_pf_payment_method();
    test_pf_transfer_state();
    test_pf_time_exactness();
    test_pf_route_type();
    test_pf_stop_type();
    test_pf_timepoint_precision();
    test_pf_location_type();
    test_pf_wheelchair_boarding();
    test_pf_transfer_type();
    test_pf_wheelchair_accessibility();
    test_pf_bike_allowance();

    test_rf_agency();
    test_rf_calendar_dates();
    test_rf_calendar();
    test_rf_fare_attributes();
    test_rf_fare_rule();
    test_rf_feed_info();
    test_rf_frequency();
    test_rf_route();
    test_rf_shape();
    test_rf_stop_time();
    test_rf_stop();
    test_rf_transfer();
    test_rf_trip();

    test_reading_utils_read_header();
    test_reading_utils_read_record();
    return 0;
}

#endif
