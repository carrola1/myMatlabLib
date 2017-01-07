function clamp_samp = real_signed_clamp(samp, width) %#codegen
    max_val = 2^(width-1)-1;

    samp_I = real(samp);
    if samp_I>max_val
        samp_I = max_val;
    elseif samp_I<-max_val
        samp_I = -max_val;
    end
    clamp_samp = samp_I;
end