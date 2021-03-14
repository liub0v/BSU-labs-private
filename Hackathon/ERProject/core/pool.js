const util = require('util');
const mysql = require('mysql');
/**
 * Connection to the database.
 *  */
const pool = mysql.createPool({
    connectionLimit: 10,
    host: 'www.db4free.net',
    user: 'liubov_k',
    database: 'er_database_2020',
    password:'e$TsY8_KCi_s$-e'
});

pool.getConnection((err, connection) => {
    if (err)
        console.error("Something went wrong connecting to the database ...");

    if (connection) {
        connection.release();
        console.log("OK!")
    }
    return;
});

pool.query = util.promisify(pool.query);

module.exports = pool;
