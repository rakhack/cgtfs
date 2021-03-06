#ifndef CGTFS_BENCH_FEED_C
#define CGTFS_BENCH_FEED_C

#define CGTFS_STORING_BATCH_TRANSACTIONS_OFF

#define CGTFS_BENCHMARKING_FEED_PATH "../tests/data/pocono_pony"

#include "_utils.c"
#include "feed.h"
#include "database/database.h"

void _bm_feed_1() {
    feed_t f;
    init_feed(&f);
    read_feed(&f, CGTFS_BENCHMARKING_FEED_PATH);
    free_feed(&f);
}

int _bm_db_1_run = 0;

void _bm_db_1() {
    feed_db_t db;
    feed_db_status_t res;

    char db_name[26];

    snprintf(db_name, 26, "tests_bench_db_%i.db", _bm_db_1_run++);

    res = init_feed_db(&db, db_name, 1);
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ init\n");

    res = setup_feed_db(&db);
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ setup\n");

    res = store_feed_db(CGTFS_BENCHMARKING_FEED_PATH, &db, NULL);  // ../tests/data/stupid_gtfs
    if (res < FEED_DB_SUCCESS)
        perror("BENCHMARK #3 failed @ store\n");

    free_feed_db(&db);
}

int _bm_db_2_run = 0;

void _bm_db_2() {
    feed_db_t db;
    feed_db_status_t res;

    char db_name[28];

    snprintf(db_name, 28, "tests_bench_dbns_%i.db", _bm_db_2_run++);

    res = init_feed_db(&db, db_name, 1);
    if (res != FEED_DB_SUCCESS)
        perror("BENCHMARK #4 failed @ init\n");

    res = import_feed_db(CGTFS_BENCHMARKING_FEED_PATH, &db);
    if (res < FEED_DB_SUCCESS)
        perror("BENCHMARK #4 failed @ import\n");

    free_feed_db(&db);
}

void bench_feed_1(void) {
    bm_results_t res = bm_init_results();

    bm_run_1(&res, _bm_feed_1);
    bm_run_10(&res, _bm_feed_1);

    bm_display_results(&res, "/ feed dir -> memory parsing");
}

void bench_db_1_semantic(void) {
    bm_results_t res = bm_init_results();

    bm_run_1(&res, _bm_db_1);
    bm_run_10(&res, _bm_db_1);

    bm_display_results(&res, "/ feed dir -> db parsing (semantic)");
}

void bench_db_2_nonsemantic(void) {
    bm_results_t res = bm_init_results();

    bm_run_1(&res, _bm_db_2);
    bm_run_10(&res, _bm_db_2);

    bm_display_results(&res, "/ feed dir -> db parsing (non-semantic)");
}

#endif