from myhdl import block, always_comb, Signal, StopSimulation

@block
def HW4Q1(f, a, b, c, d):

    """ 
    Input:  a, b, c, d
    Output: f

    """

    @always_comb
    def comb():
        # use and or not
        # or use & | ~, but only keep the LSB in the end
        # change the following line to give f correct value
        f.next = (not a and not b and not c and not d) or \
                 (a and b and not c and not d) or \
                 (not a and b and c and not d) or \
                 (not a and not b and c and d) or \
                 (a and not b and not c and d) or \
                 (a and b and c and d)

    # return the logic  
    return comb

if __name__ == "__main__":
    from myhdl import intbv, delay, instance

    # testbench itself is a block
    @block
    def test_comb():

        # create signals
        a, b, c, d, f = [Signal(bool(0)) for i in range(5)]

        # instantiating a block and connect to signals
        tut = HW4Q1(f, a, b, c, d)

        @instance
        def stimulus():
            print("a b c d | f")
            for i in range(16):
                # set a and b's value and wait for c to change
                a.next, b.next, c.next, d.next = intbv(i)[4:] 
                yield delay(10)
                print("{} {} {} {} | {}".format(int(a), int(b), int(c), int(d), int(f)))
            # stop simulation
            raise StopSimulation()

        return tut, stimulus

    tb = test_comb()
    tb.config_sim(trace=False)
    tb.run_sim()
