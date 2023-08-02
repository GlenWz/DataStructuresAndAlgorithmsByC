
//1、引入http模块
//const axios=require('axios');
const https=require('https');
//引入cheerio
const  cheerio=require('cheerio');
const fs=require('fs')
//const { find } = require('cheerio/lib/api/traversing');
let allData=[];
let data51=[];
//2、创建请求

//'https://usafacts.org/visualizations/coronavirus-covid-19-spread-map'
//https://www.corona.help/country/united-states
https.get('https://www.worldometers.info/coronavirus/country/us/',
function(res){

	//分段返回的 自己拼接
	let html='';
	//有数据产生的时候 拼接
	res.on('data',function(chunk){
		html+=chunk;
	})
	//拼接完成
	res.on('end',function(){
		//console.log(html);  //yes
		//let htmlStr=Buffer.concat(html).toString('utf-8');
		let $=cheerio.load(html);
		//console.log(html);

		//console.log($.html()); //yes
		//console.log($('.tab-content .total_row_usa').find('td').eq(2).html()); //yes
		let usaTotal=$('.tab-content .total_row_usa').find('td').eq(2).html();
		let usaDeath=$('.tab-content .total_row_usa').find('td').eq(4).html();
		console.log(usaTotal,usaDeath);
		console.log(typeof usaDeath);
		console.log("*************");
		let i=0;
		$('.tab-content').find('tbody').find('tr').each(function(){
			let tmpJson={
				name:null,
				totalCases:null,
				totalDeath:null
			}
			if(i===0){
				tmpJson.name="USA Total";
				
			}else{
				tmpJson.name=$('.mt_a',this).html();
			}
			
			let tmpTotalCases=($('td',this).eq(2).html()).replace(/\,/g,"");
			tmpJson.totalCases=Number(tmpTotalCases);
			let tmpTotalDeath=($('td',this).eq(4).html()).replace(/\,/g,"");
			tmpTotalDeath=tmpTotalDeath.replace('\n','');
			tmpJson.totalDeath=Number(tmpTotalDeath);
			
			//console.log(tmpJson);
			allData.push(tmpJson);
			//console.log(allData[i].name+":"+allData[i].totalCases+allData[i].totalDeath);
			i++;
		})
		
		//51个州+1个特别行政区+一个USA totalNum
		const statesNum=53;
		for(i=0;i<statesNum;i++){
			data51.push(allData[i]);		
		}
		for(i=0;i<statesNum;i++){
			if(data51[i].name==null){
				let tmp=data51[52];
				tmp.name="Puerto Rico";
				data51[52]=data51[i];
				data51[i]=tmp;
			}
		}
		
		for(i=1;i<statesNum-1;i++){
			for(let j=1;j<statesNum-1;j++){
				if(data51[i].name<data51[j].name){
					let tmp=data51[i];
					data51[i]=data51[j];
					data51[j]=tmp;
				}
			}
		}
		console.log(data51);
		/*
		for(i=0;i<statesNum;i++){
			console.log(data51[i]);
		}
		*/
		fs.writeFile('./usaCases.json',JSON.stringify(data51),function(err){
			if(!err){
				console.log('文件写入完毕！');
			}
		})
	})
})
