// flight_sql_library.h
#pragma once

#include <filesystem>

// Constants
const std::string DEFAULT_FLIGHT_HOSTNAME = "0.0.0.0";
const int DEFAULT_FLIGHT_PORT = 31337;

enum class BackendType {
    duckdb,
    sqlite
};

namespace fs = std::filesystem;

/**
 * @brief Run a Flight SQL Server with the specified configuration.
 *
 * This function initializes and runs a Flight SQL Server with the given parameters.
 *
 * @param backend The backend to use (duckdb or sqlite).
 * @param database_filename The path to the database file.
 * @param hostname The hostname for the Flight SQL Server. Default is "" - if so, we use environment variable: "FLIGHT_HOSTNAME",
 *   and fallback to: DEFAULT_FLIGHT_HOSTNAME if that is not set.
 * @param port The port to listen on for the Flight SQL Server. Default is DEFAULT_FLIGHT_PORT
 * @param username The username to use for authentication. Default is "flight_username" - if not set, we use environment variable: "FLIGHT_USERNAME",
 *   if both are not set, we exit with an error.
 * @param password The password for authentication. Default is "" - if so, we use environment variable: "FLIGHT_PASSWORD",
 *   if both are not set, we exit with an error.
 * @param secret_key The secret key for authentication. Default is "", if so, we use environment variable: "SECRET_KEY",
     and fallback to a random string if both are not set.
 * @param tls_cert_path The path to the TLS certificate file (PEM format). Default is an empty path.
 * @param tls_key_path The path to the TLS private key file (PEM format). Default is an empty path.
 * @param mtls_ca_cert_path The path to the mTLS CA certificate file used to verify clients (in PEM format). Default is an empty path.
 * @param init_sql_commands The initial SQL commands to execute. Default is "" - if not set, we use environment variable: "INIT_SQL_COMMANDS".
 * @param init_sql_commands_file The path to a file containing initial SQL commands. Default is an empty path - if not set, we use environment variable: "INIT_SQL_COMMANDS_FILE"
 * @param print_queries Set to true if SQL queries should be printed; false otherwise. Default is false.
 *
 * @return Returns an integer status code. 0 indicates success, and non-zero values indicate errors.
 */

extern "C" {
int RunFlightSQLServer(
        const BackendType backend,
        fs::path &database_filename,
        std::string hostname = "",
        const int &port = DEFAULT_FLIGHT_PORT,
        std::string username = "flight_username",
        std::string password = "",
        std::string secret_key = "",
        fs::path tls_cert_path = fs::path(),
        fs::path tls_key_path = fs::path(),
        fs::path mtls_ca_cert_path = fs::path(),
        std::string init_sql_commands = "",
        fs::path init_sql_commands_file = fs::path(),
        const bool &print_queries = false
);
}
