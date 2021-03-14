let video;
let webcamStream;

function startWebcam() {

    navigator.mediaDevices.getUserMedia({
        //audio: true,
        video: true
    }).then((stream) => {
        video = document.querySelector('#video');
        video.srcObject = stream;
        video.play();

        webcamStream = stream;
    }).catch((error) => {
        console.log('navigator.getUserMedia error: ', error);
    });
}
function stopWebcam() {
    webcamStream.getTracks()[0].stop();
    webcamStream.getTracks()[1].stop();
}
var canvas, ctx;

function init() {
    // Получить холст и получить контекст для
    // рисования в нём
    canvas = document.getElementById("myCanvas");
    ctx = canvas.getContext('2d');
}

function snapshot() {
    // Рисует текущее изображение из видео элемента в холст
    ctx.drawImage(video, 0,0, canvas.width, canvas.height);
}
//---------------------
// Сохранение файла с jQuery
//---------------------
$("#saveDrawing").click(function () {
//Выберите холст с идентификатором «canvas» и преобразуйте его в URL-адрес данных.
//Тип MIME, поддерживаемый почти всеми существующими браузерами, - PNG.
//Однако в зависимости от браузера могут быть доступны другие типы MIME.
    var dataURL = document.getElementById("myCanvas").toDataURL("image/png");
//Создать новый элемент привязки
    var imga = document.createElement("a");
//Сделайте его значение href как URL данных, полученный от canvas
    imga.href = dataURL;
//Это устанавливает имя файла по умолчанию
    imga.download = "myImage.png";
//Прикрепить якорь к body
    document.body.appendChild(imga);
//Активfwbz функциb щелчка, которая активирует URL-адрес данных и позволит пользователю сохранить изображение
    imga.click();
});
