const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  let answer = 0,
    passport = {};
  let input = (
    await fs.readFile(path.join(__dirname + '/4.txt'), 'utf8')
  ).split('\n');
  input.push('');

  input.forEach((line) => {
    line = line.trim();
    if (!line) {
      let valid = true;
      const properties = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'];

      if (!('byr' in passport) || 1920 <= parseInt(passport['byr']) <= 2002) {
        valid = false;
      } else if (
        !('iyr' in passport) ||
        2010 <= parseInt(passport['iyr']) <= 2020
      ) {
        valid = false;
      } else if (
        !('eyr' in passport) ||
        2020 <= parseInt(passport['eyr']) <= 2030
      ) {
        valid = false;
      } else if (
        !('iyr' in passport) ||
        2010 <= parseInt(passport['iyr']) <= 2020
      ) {
        valid = false;
      }

      if ('hcl' in passport) {
        const { hcl } = passport;
        if (
          !hcl.startsWith('#') ||
          hcl.length !== 7 ||
          !hcl.substring(1, 7).match(/[a-f0-9]/g)
        ) {
          valid = false;
        }
      }

      if ('ecl' in passport) {
        const { ecl } = passport;
        if (!['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'].includes(ecl)) {
          valid = false;
        }
      }

      if (
        !('pid' in passport) ||
        !passport.pid.match(/[0-9]/g) ||
        passport.pid.length !== 9
      ) {
        valid = false;
      }

      properties.forEach((field) => {
        if (!passport.hasOwnProperty(field)) {
          valid = false;
        }
      });

      if (valid) {
        answer++;
      }

      passport = {};
    } else {
      const words = line.split(' ');

      words.forEach((word) => {
        const [field, value] = word.split(':');
        passport[field] = value;
      });
    }
  });

  console.log(answer);
};

main();
