<h1>arglyzer - Simple Argument Analyzer</h1>

<ul>
<li><h4>Building arglyzer tester</h4>
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
<ul><li>File example.c
<pre><code>#include &ltarglyzer/arglyzer.h&gt
#include &ltstdio.h&gt

#define N_OPTIONS 3

int main(int argc, char *argv[])
{
    ResultPtr res;
    OptionPtr option_a = create_option('a', "--long-optiona", 0);
    OptionPtr option_b = create_option('b', "--long-optionb", 1);
    OptionPtr option_c = create_option('c', "--long-optionc", 2);
    OptionPtr options[N_OPTIONS + 1] = {option_a, option_b, option_c, NULL};

    if ((res = analyze(argc, argv, options)) == NULL) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }

    print_result(res);

    free_option(option_a);
    free_option(option_b);
    free_option(option_c);
    free_result(res);

    return 0;
}
</code></pre></li>
<li>Build example.c
<pre><code>gcc -o example example.c -larglyzer</pre></code></li>

<li>Execute example
<pre><code>./example -a --long-optionb paramb -c paramc1 paramc2 paramc3 param1 param2</code></pre></li>

<li>Output
<pre><code>Option[-a] : long name=--long-optiona nparams=0 found=1 params={}
Option[-b] : long name=--long-optionb nparams=1 found=1 params={paramb }
Option[-c] : long name=--long-optionc nparams=2 found=1 params={paramc1 paramc2 }
Param[0] : param1
Param[1] : param2</code></pre></li></ul></li></ul>
