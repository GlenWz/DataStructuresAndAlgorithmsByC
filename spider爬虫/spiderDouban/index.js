const https = require('https');
const cheerio = require('cheerio');

async function getMovieData(url) {
  return new Promise((resolve, reject) => {
    https.get(`https://movie.douban.com/top250?start=${url}&filter=`, function (res) {
      let html = '';
      res.on('data', function (chunk) {
        html += chunk;
      });
      res.on('end', function () {
        let $ = cheerio.load(html);
        let movieData = [];
        for (let i = 0; i < 25; i++) {
          let tmpLi = $('.grid_view').find('li').eq(i).html();
          let $2 = cheerio.load(tmpLi);
          let moviewName = $2('.hd').find('span').eq(0).html();
          let directorName = $2('.bd').find('p').eq(0).html();
          movieData.push({ moviewName, directorName });
        }
        resolve(movieData);
      });
    }).on("error", (e) => {
      reject(e);
    });
  });
}

(async () => {
  try {
    let movieData;
    for (let i = 0; i < 10; i++) {
        movieData = await getMovieData(i*25);
        console.log(movieData);
        console.log("...................................");
    }
    
  } catch (error) {
    console.error(error);
  }
})();
