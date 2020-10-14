const app = require('express')();
const bodyParser = require('body-parser');

const port = 10043;

app.use(bodyParser.json());

app.post('/', (req, res) => {
	const data = req.body;

	console.log(`Problem name: ${data.name}`);
	console.log('Full body:');
	console.log(JSON.stringify(data, null, 4));

	const inner_dir = `tasks`
	const current_dir = `${inner_dir}/${data.languages.java.taskClass}`;
	const file_name = `sol`;
	const execute_ide = `/opt/clion-2020.2/bin/clion.sh`;
	// const execute_ide = `subl`;
	const template = `/home/fakhoury/Documents/competitive-programming/lib/General/template.cpp`;

	const line_number = `30`;
	// const command_line = `:`;
	const command_line = `--line `;

	const goto_line = `${command_line}${line_number}`;

	const open_ide = `${execute_ide} ${goto_line} ${current_dir}/${file_name}.cpp`
	// const open_ide = `${execute_ide} ${current_dir}/${file_name}.cpp${goto_line}`

	const bash_template=`/home/fakhoury/Documents/competitive-programming/Solves/friend-competitive-companion/bash_template.sh`
	const bash_file=`test.sh`

	fs = require('fs');
	const { exec } = require("child_process");

	// cria o arquivo fonte
	exec(`mkdir ${inner_dir}`, function(err) {
		console.log(`Created inner directory ${err}`);
	});

	exec(`mkdir ${current_dir}`, function(err) {
		console.log(`Created directory ${err}`);
	});

	exec(`cp ${template} ${current_dir}/${file_name}.cpp`, function(err) {
		if (err) return console.log(err);
		console.log(`Created source ${file_name}`);
	});

	// abre o arquivo fonte
	exec(`${open_ide}`, function(err) {
		if (err) return console.log(err);
	});
	
	// cria os arquivos de teste
	for (var test in data.tests) {
		fs.writeFile(`${current_dir}/${test}.in`, `${data.tests[test].input}`, function(err) {
			if (err) return console.log(err);
			console.log(`Created input ${test}`);
		});

		fs.writeFile(`${current_dir}/${test}.out`, `${data.tests[test].output}`, function(err) {
			if (err) return console.log(err);
			console.log(`Created output ${test}`);
		});
	}

	// cria o tester em bash
	exec(`cp ${bash_template} ${current_dir}/${bash_file}`, function(err) {
		if (err) return console.log(err);
		console.log(`Created tester ${bash_file}`);
	});

	// cria o tester em bash
	exec(`chmod +x ${current_dir}/${bash_file}`, function(err) {
		if (err) return console.log(err);
		console.log(`Changed permissions ${bash_file}`);
	});


	res.sendStatus(200);
});

app.listen(port, err => {
	if (err) {
		console.error(err);
		process.exit(1);
	}

	console.log(`Listening on port ${port}`);
});
