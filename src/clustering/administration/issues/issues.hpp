// Copyright 2010-2014 RethinkDB, all rights reserved.
#ifndef CLUSTERING_ADMINISTRATION_ISSUES_ISSUES_HPP_
#define CLUSTERING_ADMINISTRATION_ISSUES_ISSUES_HPP_

#include <string>
#include <vector>

#include "errors.hpp"
#include <boost/shared_ptr.hpp>

#include "rdb_protocol/artificial_table/backend.hpp"
#include "clustering/administration/metadata.hpp"
#include "concurrency/watchable.hpp"

class admin_tracker_t;

class issues_artificial_table_backend_t :
    public artificial_table_backend_t
{
public:
    explicit issues_artificial_table_backend_t(const admin_tracker_t &_admin_tracker);

    std::string get_primary_key_name();

    bool read_all_primary_keys(signal_t *interruptor,
                               std::vector<ql::datum_t> *keys_out,
                               std::string *error_out);

    bool read_row(ql::datum_t primary_key,
                  signal_t *interruptor,
                  ql::datum_t *row_out,
                  std::string *error_out);

    bool write_row(ql::datum_t primary_key,
                   bool pkey_was_autogenerated,
                   ql::datum_t new_value,
                   signal_t *interruptor,
                   std::string *error_out);

private:
    const admin_tracker_t &admin_tracker;
};

#endif /* CLUSTERING_ADMINISTRATION_ISSUES_ISSUES_HPP_ */
