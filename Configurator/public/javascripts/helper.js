

polltimer = undefined

cached_config = {}
function init2()
{
    getConfigAjax(function(data){
        cached_config = data;
        refreshConfigItems(data);
    })

    getCalDataAjax(function(data) {
        var dataobj = data;
        buildTable(dataobj)
        console.log(JSON.stringify(data))
    })


    polltimer = setInterval(function(){
        getCalDataAjax(function(data) {
            var dataobj = data;
            buildTable(dataobj)
            console.log(JSON.stringify(data))
        })
        // poll for data.
    },3000)

    document.getElementById("btnsave").onclick = function(){

        var data = {};
        data.crop_y_start = parseInt(document.getElementById("cropys").value);
        data.crop_y_end = parseInt(document.getElementById("cropye").value);

        data.crop_x_start = parseInt(document.getElementById("cropxs").value);
        data.crop_x_end = parseInt(document.getElementById("cropxe").value);

        data.filterByColor = document.getElementById("fbc").checked;
        data.blobColor = parseInt(document.getElementById("blobcolor").value);
        data.minColor = parseInt(document.getElementById("mincolor").value);
        data.maxColor =  parseInt(document.getElementById("maxcolor").value);

        data.filterByArea = document.getElementById("fba").checked;
        data.minArea = parseInt(document.getElementById("minarea").value);
        data.maxArea = parseInt(document.getElementById("maxarea").value);

        data.filterByCircularity = document.getElementById("fbcir").checked;
        data.minCircularity = parseInt(document.getElementById("mincircle").value);

        data.filterByConvexity = document.getElementById("fbcon").checked;
        data.minConvexity = parseInt(document.getElementById("mincon").value);
        data.maxConvexity = parseInt(document.getElementById("maxcon").value);

        data.filterByInertia =  document.getElementById("fbi").checked;
        data.minInertiaRatio =parseInt(document.getElementById("mini").value);

        setConfig(data,function(retconfig) {
            cached_config = retconfig;
            refreshConfigItems(retconfig);
        })
    }



}

function getConfigAjax(callback) {

    $.ajax({
        url: "/getconfig",
        type: 'get',
        dataType: "json",
        contentType: "application/json; charset=utf-8",
        success: function (result) {
            callback(result);
        },
        error: function (xhr, ajaxOptions, thrownError) {
            if(xhr != undefined && xhr.responseText != undefined) {
                window.location = "/error500";
            }
        }
    });
}



function setConfig(obj, callback) {

    var dataset = JSON.stringify(obj);
    $.ajax({
        url: "/setconfig",
        type: 'post',
        data: dataset,
        dataType: "json",
        contentType: "application/json; charset=utf-8",
        success: function (result) {
            callback(result);
        },
        error: function (xhr, ajaxOptions, thrownError) {
            if(xhr != undefined && xhr.responseText != undefined) {
                window.location = "/error500";
            }
        }
    });
}


function refreshConfigItems(data)
{
    document.getElementById("cropys").value = data.crop_y_start;

    document.getElementById("cropye").value = data.crop_y_end;
    document.getElementById("cropxs").value = data.crop_x_start;
    document.getElementById("cropxe").value = data.crop_x_end;

    document.getElementById("fbc").checked = data.filterByColor;
    document.getElementById("blobcolor").value = data.blobColor;
    document.getElementById("mincolor").value = data.minColor;
    document.getElementById("maxcolor").value = data.maxColor;

    document.getElementById("fba").checked = data.filterByArea;
    document.getElementById("minarea").value = data.minArea;
    document.getElementById("maxarea").value = data.maxArea;

    document.getElementById("fbcir").checked = data.filterByCircularity;
    document.getElementById("mincircle").value = data.minCircularity;

    document.getElementById("fbcon").checked = data.filterByConvexity;
    document.getElementById("mincon").value = data.minConvexity;
    document.getElementById("maxcon").value = data.maxConvexity;

    document.getElementById("fbi").checked = data.filterByInertia;
    document.getElementById("mini").value = data.minInertiaRatio;

}




function getCalDataAjax(callback) {

    $.ajax({
        url: "/getcaldata",
        type: 'get',
        dataType: "json",
        contentType: "application/json; charset=utf-8",
        success: function (result) {
            callback(result);
        },
        error: function (xhr, ajaxOptions, thrownError) {
            if(xhr != undefined && xhr.responseText != undefined) {
                window.location = "/error500";
            }
        }
    });
}


function buildTable(mydata)
{

    // EXTRACT VALUE FOR HTML HEADER.
    var col = [];
    for (var i = 0; i < mydata.length; i++) {
        for (var key in mydata[i]) {
            if (col.indexOf(key) === -1) {
                col.push(key);
            }
        }
    }
    // CREATE DYNAMIC TABLE.
    var table = document.createElement("table");

    // CREATE HTML TABLE HEADER ROW USING THE EXTRACTED HEADERS ABOVE.

    var tr = table.insertRow(-1);                   // TABLE ROW.

    for (var i = 0; i < col.length; i++) {
        var th = document.createElement("th");      // TABLE HEADER.
        th.innerHTML = col[i];
        tr.appendChild(th);
    }

    // ADD JSON DATA TO THE TABLE AS ROWS.
    for (var i = 0; i < mydata.length; i++) {

        tr = table.insertRow(-1);

        for (var j = 0; j < col.length; j++) {
            var tabCell = tr.insertCell(-1);
            tabCell.innerHTML = mydata[i][col[j]];
        }
    }

    // FINALLY ADD THE NEWLY CREATED TABLE WITH JSON DATA TO A CONTAINER.
    var divContainer = document.getElementById("tableholder");
    divContainer.innerHTML = "";
    divContainer.appendChild(table);

}
