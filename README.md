<h1>arglyzer - Simple Argument Analyzer</h1>

<ul>
<li><h4>Build</h4>
<pre><code>mkdir build
cd build
cmake ..
make
</code></pre></li>
<li><h4>Install</h4>
<pre><code>su
make install
</code></pre></li>
<li><h4>Quick Example</h4>
<ul><li>File example1.c
<pre><code>#include &ltstdio.h&gt
#include &ltarglyzer/arglyzer.h&gt

int main(int argc, char *argv[])
{
    ResultPtr res;
    OptionsListPtr options_list = create_options_list();

    add_option(options_list, create_option('a', "--long-optiona", 0));
    add_option(options_list, create_option('b', "--long-optionb", 1));
    add_option(options_list, create_option('c', "--long-optionc", 2));

    if ((res = analyze(argc, argv, options_list)) == NULL) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }

    print_result(res);

    free_result(res);
    free_options_list(options_list);

    return 0;
}
</code></pre></li>
<li>Build example.c
<pre><code>gcc -o example1 example1.c -larglyzer</pre></code></li>

<li>Execute example
<pre><code>./example1 -a --long-optionb paramb -c paramc1 paramc2 param1 param2</code></pre></li>

<li>Output
<pre><code>Option[-c] : long name=--long-optionc nparams=2 found=1 params={paramc1 paramc2 }
Option[-b] : long name=--long-optionb nparams=1 found=1 params={paramb }
Option[-a] : long name=--long-optiona nparams=0 found=1 params={}
Param[0] : param1
Param[1] : param2</code></pre></li></ul></li></ul>
