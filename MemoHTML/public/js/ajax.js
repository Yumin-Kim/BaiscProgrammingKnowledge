window.onload = () => {
    console.log(window.location.pathname)
    function getlist(data){
        const xhr = new XMLHttpRequest();
        xhr.open('post',`/subpage`);
        xhr.setRequestHeader('Content-Type', 'application/json' );
        xhr.send(data);
        xhr.addEventListener('load',()=>{
            const { mkdir , result } = JSON.parse(xhr.responseText)
            if(mkdir){
                document.querySelector('.result').textContent=result    
            }else{
                const listBox =  document.querySelector('.subCategory');
                listBox.innerHTML = '';
                for( let i = 0 ; i < result.length -1 ; i++ ){
                    if( i % 2 === 0){
                    let li = document.createElement('li');
                    listBox.append(li);
                        li.innerHTML = `<a class="link" href="${result[i]}">${result[i+1]}</a>`;
                    }
                }
            }
            forms.elements[0].value = '';
            forms.elements[1].value = '';
        });
    }

    getlist(JSON.stringify({url:window.location.pathname.split('/')[1]}));
    
    const forms =document.querySelector('form'); 
    forms.elements[2].addEventListener('click',(e)=>{
        const data = {
            title:forms.elements[0].value,
            description:forms.elements[1].value,
            url:window.location.pathname.split('/')[1],
        }
        const dataString = JSON.stringify(data);
        e.preventDefault();
        getlist(dataString);
    });
}