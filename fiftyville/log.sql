-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE year = 2024 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
SELECT * FROM interviews WHERE year = 2024 AND month = 7 AND day = 28;
SELECT license_plate FROM bakery_security_logs WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit';
SELECT name FROM people WHERE license_plate IN (
  '5P2BI95', '94KL13X', '6P58WS2', '4328GD8',
  'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55'
);
SELECT account_number FROM atm_transactions WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';
SELECT caller, receiver FROM phone_calls WHERE year = 2024 AND month = 7 AND day = 28 AND duration < 60;
SELECT name FROM people
WHERE phone_number IN (
  '(130) 555-0289',
  '(499) 555-9472',
  '(367) 555-5533',
  '(286) 555-6063',
  '(770) 555-1861',
  '(031) 555-6622',
  '(826) 555-1652',
  '(338) 555-6650',
  '(831) 555-6622'
);
SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND year = 2024 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = 36;
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);
SELECT name FROM people WHERE phone_number = '(676) 555-6554';

